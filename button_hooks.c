/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:35:51 by prranges          #+#    #+#             */
/*   Updated: 2021/10/07 10:35:57 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	buttons_hook_move(t_data *g, char c)
{
	g->vector = c;
	if (c == 'L')
		g->p.p_x -= X;
	if (c == 'D')
		g->p.p_y += X;
	if (c == 'U')
		g->p.p_y -= X;
	if (c == 'R')
		g->p.p_x += X;
	g->moves++;
	printf("Moves -> %d\n", g->moves);
	return (c);
}

void	restart(t_data *g)
{
	int	i;

	i = -1;
	while (g->map.map[++i])
		free(g->map.map[i]);
	g->start_time.tv_sec = current_time(g);
	start(g);
}

int	buttons_hook(int key, t_data *g)
{
	if (key == START)
	{
		g->start_time.tv_sec = current_time(g);
		g->time_for_game = 40;
		g->start_game = 1;
	}
	if (key == ESC)
		close_win(g);
	if (key == RESTART && BONUS)
		restart(g);
	if (!g->f_loose && !g->f_win && g->start_game > 0)
	{
		if (key == LEFT &&	g->map.map[(g->p.p_y - X) / X][(g->p.p_x - X) / X] != '1' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x - X) / X] != '2' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x - X) / X] != 'B' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x - X) / X] != 'H')
			buttons_hook_move(g, 'L');
		if (key == DOWN && g->map.map[(g->p.p_y) / X][g->p.p_x / X] != '1' && g->map.map[(g->p.p_y) / X][g->p.p_x / X] != '2' && g->map.map[(g->p.p_y) / X][g->p.p_x / X] != 'B' && g->map.map[(g->p.p_y) / X][g->p.p_x / X] != 'H')
			buttons_hook_move(g, 'D');
		if (key == UP && g->map.map[(g->p.p_y - X * 2) / X][g->p.p_x / X] != '1' && g->map.map[(g->p.p_y - X * 2) / X][g->p.p_x / X] != '2' && g->map.map[(g->p.p_y - X * 2) / X][g->p.p_x / X] != 'B' && g->map.map[(g->p.p_y - X * 2) / X][g->p.p_x / X] != 'H')
			buttons_hook_move(g, 'U');
		if (key == RIGHT && g->map.map[(g->p.p_y - X) / X][(g->p.p_x + X) / X] != '1' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x + X) / X] != '2' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x + X) / X] != 'B' && g->map.map[(g->p.p_y - X) / X][(g->p.p_x + X) / X] != 'H')
			buttons_hook_move(g, 'R');
	}
	return (key);
}
