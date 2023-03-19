/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:42:11 by prranges          #+#    #+#             */
/*   Updated: 2021/09/19 12:59:30 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_player_xpm(t_data *g)
{
	int		w;
	int		h;

	g->p.t_player_d1 = mlx_xpm_file_to_image(g->mlx, PLAYER_D1, &w, &h);
	g->p.t_player_d2 = mlx_xpm_file_to_image(g->mlx, PLAYER_D2, &w, &h);
	g->p.t_player_d3 = mlx_xpm_file_to_image(g->mlx, PLAYER_D3, &w, &h);
	g->p.t_player_d4 = mlx_xpm_file_to_image(g->mlx, PLAYER_D4, &w, &h);
	g->p.t_player_l1 = mlx_xpm_file_to_image(g->mlx, PLAYER_L1, &w, &h);
	g->p.t_player_l2 = mlx_xpm_file_to_image(g->mlx, PLAYER_L2, &w, &h);
	g->p.t_player_l3 = mlx_xpm_file_to_image(g->mlx, PLAYER_L3, &w, &h);
	g->p.t_player_l4 = mlx_xpm_file_to_image(g->mlx, PLAYER_L4, &w, &h);
	g->p.t_player_u1 = mlx_xpm_file_to_image(g->mlx, PLAYER_U1, &w, &h);
	g->p.t_player_u2 = mlx_xpm_file_to_image(g->mlx, PLAYER_U2, &w, &h);
	g->p.t_player_u3 = mlx_xpm_file_to_image(g->mlx, PLAYER_U3, &w, &h);
	g->p.t_player_u4 = mlx_xpm_file_to_image(g->mlx, PLAYER_U4, &w, &h);
	g->p.t_player_r1 = mlx_xpm_file_to_image(g->mlx, PLAYER_R1, &w, &h);
	g->p.t_player_r2 = mlx_xpm_file_to_image(g->mlx, PLAYER_R2, &w, &h);
	g->p.t_player_r3 = mlx_xpm_file_to_image(g->mlx, PLAYER_R3, &w, &h);
	g->p.t_player_r4 = mlx_xpm_file_to_image(g->mlx, PLAYER_R4, &w, &h);
	g->p.t_player = g->p.t_player_d1;
}

void	read_xpm(t_data *g)
{
	int		w;
	int		h;

	g->t_floor_green = mlx_xpm_file_to_image(g->mlx, FLOOR_GREEN, &w, &h);
	g->t_floor_red = mlx_xpm_file_to_image(g->mlx, FLOOR_RED, &w, &h);
	g->t_floor_tree_green = mlx_xpm_file_to_image(g->mlx, FLOOR_TREE, &w, &h);
	g->t_floor_tree_red = mlx_xpm_file_to_image(g->mlx, FLOOR_TREE_RED, &w, &h);
	g->t_floor_0 = g->t_floor_green;
	g->t_floor_2 = g->t_floor_tree_green;
	g->t_floor_3 = g->t_floor_green;
	
	g->t_wall = mlx_xpm_file_to_image(g->mlx, WALL, &w, &h);
	
	g->t_wall_left = mlx_xpm_file_to_image(g->mlx, WALL_L, &w, &h);
	g->t_wall_right = mlx_xpm_file_to_image(g->mlx, WALL_R, &w, &h);
	g->t_wall_up = mlx_xpm_file_to_image(g->mlx, WALL_U, &w, &h);
	g->t_wall_down = mlx_xpm_file_to_image(g->mlx, WALL_D, &w, &h);
	g->t_corner_lu = mlx_xpm_file_to_image(g->mlx, CORNER_LU, &w, &h);
	g->t_corner_ru = mlx_xpm_file_to_image(g->mlx, CORNER_RU, &w, &h);
	g->t_corner_ld = mlx_xpm_file_to_image(g->mlx, CORNER_LD, &w, &h);
	g->t_corner_rd = mlx_xpm_file_to_image(g->mlx, CORNER_RD, &w, &h);
	
	g->c.t_money_1 = mlx_xpm_file_to_image(g->mlx, MONEY1, &w, &h);
	g->c.t_money_2 = mlx_xpm_file_to_image(g->mlx, MONEY2, &w, &h);
	g->c.t_money_3 = mlx_xpm_file_to_image(g->mlx, MONEY3, &w, &h);
	g->c.t_money_4 = mlx_xpm_file_to_image(g->mlx, MONEY4, &w, &h);
	g->c.t_money_5 = mlx_xpm_file_to_image(g->mlx, MONEY5, &w, &h);
	g->c.t_money_6 = mlx_xpm_file_to_image(g->mlx, MONEY6, &w, &h);
	g->c.t_money_7 = mlx_xpm_file_to_image(g->mlx, MONEY7, &w, &h);
	g->c.t_money = g->c.t_money_1;
	g->t_exit_red = mlx_xpm_file_to_image(g->mlx, EXIT_RED, &w, &h);
	g->t_exit_green = mlx_xpm_file_to_image(g->mlx, EXIT_GREEN, &w, &h);
	g->t_exit = g->t_exit_green;
	read_player_xpm(g);
	g->e.t_enemy1 = mlx_xpm_file_to_image(g->mlx, ENEMY1, &w, &h);
	g->e.t_enemy2 = mlx_xpm_file_to_image(g->mlx, ENEMY2, &w, &h);
	g->e.t_enemy3 = mlx_xpm_file_to_image(g->mlx, ENEMY3, &w, &h);
	g->e.t_enemy4 = mlx_xpm_file_to_image(g->mlx, ENEMY4, &w, &h);
	g->e.t_enemy5 = mlx_xpm_file_to_image(g->mlx, ENEMY5, &w, &h);
	g->e.t_enemy6 = mlx_xpm_file_to_image(g->mlx, ENEMY6, &w, &h);
	g->e.t_enemy = g->e.t_enemy1;
	g->e.t_doll_0 = mlx_xpm_file_to_image(g->mlx, DOLL_0, &w, &h);
	g->e.t_doll_1 = mlx_xpm_file_to_image(g->mlx, DOLL_1, &w, &h);
	g->e.t_doll_2 = mlx_xpm_file_to_image(g->mlx, DOLL_2, &w, &h);
	g->e.t_doll_3 = mlx_xpm_file_to_image(g->mlx, DOLL_3, &w, &h);
	g->e.t_doll_4 = mlx_xpm_file_to_image(g->mlx, DOLL_3, &w, &h);
	g->e.t_doll_body = mlx_xpm_file_to_image(g->mlx, DOLL_BODY, &w, &h);
	g->e.t_doll = g->e.t_doll_4;
	g->t_you_win = mlx_xpm_file_to_image(g->mlx, U_WIN, &w, &h);
	g->t_you_loose = mlx_xpm_file_to_image(g->mlx, U_LOOSE, &w, &h);
	g->t_start_screen = mlx_xpm_file_to_image(g->mlx, START_SCREEN, &w, &h);
}
