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

void	player_animation(t_data *g)
{
	if (g->vector == 'L')
		player_animation_l(g);
	if (g->vector == 'D')
		player_animation_d(g);
	if (g->vector == 'U')
		player_animation_u(g);
	if (g->vector == 'R')
		player_animation_r(g);
}

void	player_animation_d(t_data *g)
{
	static int	t = 0;

	if (t >= 0 && t < 12)
		g->p.t_player = g->p.t_player_d1;
	if (t >= 12 && t < 24)
		g->p.t_player = g->p.t_player_d2;
	if (t >= 24 && t < 36)
		g->p.t_player = g->p.t_player_d3;
	if (t >= 36 && t < 48)
		g->p.t_player = g->p.t_player_d4;
	t++;
	if (t == 48)
		t = 0;
}

void	player_animation_l(t_data *g)
{
	static int	t = 0;

	if (t >= 0 && t < 12)
		g->p.t_player = g->p.t_player_l1;
	if (t >= 12 && t < 24)
		g->p.t_player = g->p.t_player_l2;
	if (t >= 24 && t < 36)
		g->p.t_player = g->p.t_player_l3;
	if (t >= 36 && t < 48)
		g->p.t_player = g->p.t_player_l4;
	t++;
	if (t == 48)
		t = 0;
}

void	player_animation_u(t_data *g)
{
	static int	t = 0;

	if (t >= 0 && t < 12)
		g->p.t_player = g->p.t_player_u1;
	if (t >= 12 && t < 24)
		g->p.t_player = g->p.t_player_u2;
	if (t >= 24 && t < 36)
		g->p.t_player = g->p.t_player_u3;
	if (t >= 36 && t < 48)
		g->p.t_player = g->p.t_player_u4;
	t++;
	if (t == 48)
		t = 0;
}

void	player_animation_r(t_data *g)
{
	static int	t = 0;

	if (t >= 0 && t < 12)
		g->p.t_player = g->p.t_player_r1;
	if (t >= 12 && t < 24)
		g->p.t_player = g->p.t_player_r2;
	if (t >= 24 && t < 36)
		g->p.t_player = g->p.t_player_r3;
	if (t >= 36 && t < 48)
		g->p.t_player = g->p.t_player_r4;
	t++;
	if (t == 48)
		t = 0;
}
