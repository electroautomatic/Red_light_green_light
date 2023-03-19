/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_and_enemy_animation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:01 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:58:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	doll_animation_red(t_data *g)
{
	static int	t = 0;

	if (t == 48)
		t = 0;
	if (t == 1)
    {
		g->red_light_sound = 1;
		g->doll_head_sound = 1;
	}
	if (t >= 0 && t < 12)
		g->e.t_doll = g->e.t_doll_3;
	if (t >= 12 && t < 24)
		g->e.t_doll = g->e.t_doll_2;
	if (t >= 24 && t < 36)
		g->e.t_doll = g->e.t_doll_1;
	if (t >= 36 && t < 48)
		g->e.t_doll = g->e.t_doll_0;
	t++;
}

void	doll_animation_green(t_data *g)
{
	static int	t = 0;

	if (t == 48)
		t = 0;
	if (t == 1)
    {
		g->green_light_sound = 1;
        g->doll_head_sound = 1;
    }
	if (t >= 0 && t < 12)
		g->e.t_doll = g->e.t_doll_1;
	if (t >= 12 && t < 24)
		g->e.t_doll = g->e.t_doll_2;
	if (t >= 24 && t < 36)
		g->e.t_doll = g->e.t_doll_3;
	if (t >= 36 && t < 48)
		g->e.t_doll = g->e.t_doll_4;
	t++;
}

void	coin_animation(t_data *g)
{
	static int	t = 0;

	if (t < 6)
		g->c.t_money = g->c.t_money_1;
	if (t >= 6 && t < 12)
		g->c.t_money = g->c.t_money_2;
	if (t >= 12 && t < 18)
		g->c.t_money = g->c.t_money_3;
	if (t >= 18 && t < 24)
		g->c.t_money = g->c.t_money_4;
	if (t >= 24 && t < 30)
		g->c.t_money = g->c.t_money_5;
	if (t >= 30 && t < 36)
		g->c.t_money = g->c.t_money_6;
	if (t >= 36 && t < 42)
		g->c.t_money = g->c.t_money_7;
	t++;
	if (t == 42)
		t = 0;
}

void	enemy_animation(t_data *g)
{
	static int	t = 0;

	if (t < 10)
		g->e.t_enemy = g->e.t_enemy1;
	if (t >= 10 && t < 20)
		g->e.t_enemy = g->e.t_enemy2;
	if (t >= 20 && t < 30)
		g->e.t_enemy = g->e.t_enemy3;
	if (t >= 30 && t < 40)
		g->e.t_enemy = g->e.t_enemy4;
	if (t >= 40 && t < 50)
		g->e.t_enemy = g->e.t_enemy5;
	if (t >= 50 && t < 60)
		g->e.t_enemy = g->e.t_enemy6;
	t++;
	if (t == 60)
		t = 0;
}

void	move_enemy(t_data *g)
{
	int			i;
	static int	j;

	i = -1;
	while (i < g->map.e && j == 50)
	{
		while (++i < g->map.e)
		{
			g->r = rand () % 4;
			if (g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] - X) / X] \
				!= '1' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] - X) / X] \
				!= '2' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] - X) / X] \
				!= 'B' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] - X) / X] \
				!= 'H' && g->r == 0)
				g->e.e_x[i] -= X;
			else if (g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] + X) / X] \
				!= '1' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] + X) / X] \
				!= '2' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] + X) / X] \
				!= 'B' && g->map.map[(g->e.e_y[i] - X) / X][(g->e.e_x[i] + X) / X] \
				!= 'H' && g->r == 1)
				g->e.e_x[i] += X;
			else if (g->map.map[(g->e.e_y[i]) / X][g->e.e_x[i] / X] \
				!= '1' && g->map.map[(g->e.e_y[i]) / X][g->e.e_x[i] / X] \
				!= '2' && g->map.map[(g->e.e_y[i]) / X][g->e.e_x[i] / X] \
				!= 'B' && g->map.map[(g->e.e_y[i]) / X][g->e.e_x[i] / X] \
				!= 'H' && g->r == 2)
				g->e.e_y[i] += X;
			else if (g->map.map[(g->e.e_y[i] - X * 2) / X][g->e.e_x[i] / X] \
				!= '1' && g->map.map[(g->e.e_y[i] - X * 2) / X][g->e.e_x[i] / X] \
				!= '2' && g->map.map[(g->e.e_y[i] - X * 2) / X][g->e.e_x[i] / X] \
				!= 'B' && g->map.map[(g->e.e_y[i] - X * 2) / X][g->e.e_x[i] / X] \
				!= 'H' && g->r == 3)
				g->e.e_y[i] -= X;
		}
		j = 0;
	}
	j++;
}
