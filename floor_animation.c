/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:01 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:58:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor_animation(t_data *g)
{
	if (g->floor_restart >= 500 && g->floor_restart < 1000)
	{
		if (g->red_light < 48)
		{
			doll_animation_red(g);
			g->red_light++;
		}
		else
		{
			g->t_floor_0 = g->t_floor_red;
			g->t_floor_2 = g->t_floor_tree_red;
			g->t_exit = g->t_exit_red;
			g->red_light++;
		}
		if (g->map.map[(g->p.p_y - X) / X][(g->p.p_x) / X] != '3' && g->red_light > 48)
		{
			g->f_loose++;
		}
	}
	g->floor_restart++;
	if (g->floor_restart > 952)
		doll_animation_green(g);
	if (g->floor_restart == 1000)
	{
		g->t_floor_0 = g->t_floor_green;
		g->t_floor_2 = g->t_floor_tree_green;
		g->t_exit = g->t_exit_green;
		g->floor_restart = 0;
		g->red_light = 0;
	}
}

