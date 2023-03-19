/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:01 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:58:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_walls(t_data *g)
{
	if (g->map.map[0][g->map.i] != '1'
	|| g->map.map[g->map.rows - 3][g->map.i] != '1'
	|| g->map.map[g->map.j][0] != '1'
	|| g->map.map[g->map.j][(int)ft_strlen(g->map.map[g->map.j]) \
	- 1] != '1')
		g->err.e_map_no_walls++;
}

void	enemy_x_y(t_data *g, int i)
{
	g->e.e_x[i] = g->map.i * X;
	g->e.e_y[i] = (g->map.j + 1) * X;
	g->map.e++;
}

void	player_x_y(t_data *g)
{
	g->p.p_x = g->map.i * X;
	g->p.p_y = (g->map.j + 1) * X;
	g->map.p++;
}

void	check_map_rules_part(t_data *g)
{
	static int	i;

	if (g->map.e == 0)
		i = 0;
	while (g->map.map[g->map.j][++g->map.i] != '\0')
	{
		check_map_walls(g);
		if (g->map.map[g->map.j][g->map.i] == '1')
			g->map.one++;
		else if (g->map.map[g->map.j][g->map.i] == '0')
			g->map.zero++;
		else if (g->map.map[g->map.j][g->map.i] == '2' || g->map.map[g->map.j][g->map.i] == '3')
			g->map.zero++;
		else if (g->map.map[g->map.j][g->map.i] == 'P')
			player_x_y(g);
		else if (g->map.map[g->map.j][g->map.i] == 'K' && BONUS)
			enemy_x_y(g, i++);
		else if (g->map.map[g->map.j][g->map.i] == 'C')
			g->map.coin++;
		else if (g->map.map[g->map.j][g->map.i] == 'B')
			g->map.zero++;
		else if (g->map.map[g->map.j][g->map.i] == 'H')
			g->map.zero++;
		else if (g->map.map[g->map.j][g->map.i] == 'E')
			g->map.exit++;
		else
			g->err.e_map_forbidden_chars++;
	}
}

int	check_map_rules(t_data *g)
{
	g->map.i = -1;
	g->map.j = 0;
	g->map.len = (int)ft_strlen(g->map.map[0]);
	while (g->map.map[++g->map.j])
	{
		g->map.i = 0;
		if (g->map.len != (int)ft_strlen(g->map.map[g->map.j]))
			g->err.e_map_diff_row_len++;
		check_map_rules_part(g);
	}
	if (g->map.coin == 0 || g->map.p == 0 || g->map.exit == 0)
	{
		if (g->map.coin == 0)
			g->err.e_map_no_collectible++;
		if (g->map.p == 0)
			g->err.e_map_no_player++;
//		if (g->map.exit == 0)
//			g->err.e_map_no_exit++;
	}
	if (err_print(g))
		close_win(g);
	return (0);
}
