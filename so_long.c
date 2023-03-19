/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:49:05 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:52:53 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	current_time(t_data *g)
{
	gettimeofday(&g->real_time, NULL);
	return (g->real_time.tv_sec);
}

void	game_moves_to_window(t_data *g)
{
	char	*cookies = "COOKIES:";
	char	*time = "TIME:";
	
	mlx_string_put(g->mlx, g->win, 5, 5, 1409999, cookies);
	mlx_string_put(g->mlx, g->win, 100, 5, 1409999, ft_itoa(g->map.coin));
	mlx_string_put(g->mlx, g->win, 200, 5, 000255000000, time);
//	mlx_string_put(g->mlx, g->win, 260, 5, 000255000000, string); // moves
	mlx_string_put(g->mlx, g->win, 260, 5, 000255000000, ft_itoa(g->timer));
//	free(string);
}

int	update(t_data *g)
{
	if (g->start_game)
	{
		mlx_clear_window(g->mlx, g->win);
		render_frame(g);
		put_player(g);
		if (BONUS)
		{
			put_enemys(g);
			game_moves_to_window(g);
			coin_animation(g);
			if (!g->f_win && !g->f_loose)
				floor_animation(g);
			enemy_animation(g);
			move_enemy(g);
			if (!g->red_light)
				player_animation(g);
		}
		if (g->timer <= 0)
			g->f_loose++;
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->t_start_screen, \
		(g->map.len * 16) - 64, (g->map.rows - 1) * 16 - 64);
		mlx_string_put(g->mlx, g->win, ((g->map.len * 16) - 96), ((g->map.rows - 1) * 16 + 64), 000255255255, "Press SPACE to start");
		g->start_menu_sound = 1;
		
	}
	return (0);
}

int	close_win(t_data *g)
{
	int	i;

	i = -1;
	while (g->map.map[++i])
		free(g->map.map[i]);
	if (g->mlx)
	{
		mlx_clear_window(g->mlx, g->win);
		mlx_destroy_window(g->mlx, g->win);
	}
	exit (0);
}

void	start(t_data *g)
{
	err_init(g);
	map_init(g);
	create_map(g);
	check_map_rules(g);
	g->e.t_doll = g->e.t_doll_4;
}

int	main(int argc, char **argv)
{
	t_data	g;

	if (argc != 2)
	{
		if (argc > 2)
			ft_putstr_fd("Error\nTo many arguments.\n", 1);
		if (argc == 1)
			ft_putstr_fd("Error\nNo arguments.\n", 1);
		exit (1);
	}
	g.file_name = argv[1];
	g.mlx = NULL;
	start(&g);
	g.start_game = 0;
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, (int)g.map.len * X, \
	(int)(g.map.rows - 1) *X, "So long!");
	read_xpm(&g);
	start_sound_thread(&g);
	mlx_hook(g.win, 2, 0, buttons_hook, (void *)&g);
	mlx_hook(g.win, 17, 0L, close_win, (void *)&g);
	mlx_loop_hook(g.mlx, update, (void *)&g);
	mlx_loop(g.mlx);
}
