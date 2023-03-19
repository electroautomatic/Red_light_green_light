/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_err_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:41 by prranges          #+#    #+#             */
/*   Updated: 2021/09/17 15:58:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_data *g)
{
	g->map.zero = 0;
	g->map.one = 0;
	g->map.coin = 0;
	g->map.p = 0;
	g->map.e = 0;
	g->map.exit = 0;
	g->map.i = 0;
	g->map.j = 0;
	g->moves = 0;
	g->vector = 'D';
	g->f_loose = 0;
	g->f_win = 0;
	g->win_sound = 0;
	g->loose_sound = 0;
	g->c.c_sound = 0;
	g->floor_restart = 0;
	g->red_light = 0;
	g->t_floor_0 = g->t_floor_green;
	g->t_floor_2 = g->t_floor_tree_green;
	g->t_exit = g->t_exit_green;
}

void	err_init(t_data *g)
{
	g->err.e_map_no_walls = 0;
	g->err.e_map_forbidden_chars = 0;
	g->err.e_map_no_player = 0;
	g->err.e_map_no_exit = 0;
	g->err.e_map_no_collectible = 0;
	g->err.e_map_diff_row_len = 0;
}

int	err_print(t_data *g)
{
	if (g->err.e_map_no_walls > 0 || g->err.e_map_forbidden_chars > 0
		|| g->err.e_map_no_player > 0 || g->err.e_map_no_exit > 0
		|| g->err.e_map_no_collectible > 0 || g->map.p > 1)
	{
		ft_putstr_fd("Error\n", 1);
		if (g->err.e_map_no_walls > 0 && g->err.e_map_diff_row_len == 0)
			ft_putstr_fd("The map must be surrounded by walls.\n", 1);
		if (g->err.e_map_forbidden_chars > 0)
			ft_putstr_fd("Map contains forbidden characters.\n", 1);
		if (g->err.e_map_no_player > 0)
			ft_putstr_fd("There is no player on map.\n", 1);
		if (g->err.e_map_no_exit > 0)
			ft_putstr_fd("There is no exit on map.\n", 1);
		if (g->err.e_map_no_collectible > 0)
			ft_putstr_fd("There is no collectible on map.\n", 1);
		if (g->err.e_map_diff_row_len > 0)
			ft_putstr_fd("Map contains rows of different lengths.\n", 1);
		if (g->map.p > 1)
			ft_putstr_fd("Map contains more thar 1 starting position.\n", 1);
		return (1);
	}
	return (0);
}
