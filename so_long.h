/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:37 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:51:32 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# include <mlx.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>

# define X 32
# define ESC 53
# define LEFT 0
# define DOWN 1
# define UP 13
# define RIGHT 2
# define RESTART 15
# define START 49

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_coin
{
	void	*t_money;
	void	*t_money_1;
	void	*t_money_2;
	void	*t_money_3;
	void	*t_money_4;
	void	*t_money_5;
	void	*t_money_6;
	void	*t_money_7;
	int		c_sound;
}				t_coin;

typedef struct s_enemy
{
	int		e_x[50];
	int		e_y[50];
	void	*t_enemy;
	void	*t_enemy1;
	void	*t_enemy2;
	void	*t_enemy3;
	void	*t_enemy4;
	void	*t_enemy5;
	void	*t_enemy6;
	void	*t_doll;
	void	*t_doll_body;
	void	*t_doll_0;
	void	*t_doll_1;
	void	*t_doll_2;
	void	*t_doll_3;
	void	*t_doll_4;
}				t_enemy;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	void	*t_player;
	void	*t_player_d1;
	void	*t_player_d2;
	void	*t_player_d3;
	void	*t_player_d4;
	void	*t_player_d5;
	void	*t_player_l1;
	void	*t_player_l2;
	void	*t_player_l3;
	void	*t_player_l4;
	void	*t_player_r1;
	void	*t_player_r2;
	void	*t_player_r3;
	void	*t_player_r4;
	void	*t_player_u1;
	void	*t_player_u2;
	void	*t_player_u3;
	void	*t_player_u4;
}				t_player;

typedef struct s_err
{
	int	e_map_no_walls;
	int	e_map_forbidden_chars;
	int	e_map_no_player;
	int	e_map_no_exit;
	int	e_map_no_collectible;
	int	e_map_diff_row_len;
}				t_err;

typedef struct s_map
{
	int		i;
	int		j;
	char	**map;
	int		zero;
	int		one;
	int		coin;
	int		p;
	int		e;
	int		exit;
	int		rows;
	int		len;
}				t_map;

typedef struct s_data
{
	struct s_map	map;
	struct s_err	err;
	struct s_player	p;
	struct s_enemy	e;
	struct s_coin	c;
	int				i;
	int				j;
	void			*mlx;
	void			*win;
	char			*addr;
	void			*t_floor_0;
	void			*t_floor_2;
	void			*t_floor_3;
	void			*t_floor_green;
	void			*t_floor_red;
	void			*t_floor_tree_green;
	void			*t_floor_tree_red;
	void			*t_wall;
	void			*t_wall_left;
	void			*t_wall_right;
	void			*t_wall_up;
	void			*t_wall_down;
	void			*t_corner_lu;
	void			*t_corner_ru;
	void			*t_corner_ld;
	void			*t_corner_rd;
	void			*t_exit;
	void			*t_exit_green;
	void			*t_exit_red;
	void			*t_you_loose;
	void			*t_you_win;
	void			*t_start_screen;
	int				moves;
	char			vector;
	int				f_loose;
	int				f_win;
	char			*file_name;
	int				r;
	struct timeval	real_time;
	struct timeval	start_time;
	long			timer;
	long			time_for_game;
	int				win_sound;
	int				start_menu_sound;
	int				doll_head_sound;
	int				green_light_sound;
	int				red_light_sound;
	int				loose_sound;
	int				red_light;
	int				floor_restart;
	int				start_game;
}				t_data;

int		map_ber_check(char *argv);
int		buttons_hook(int key, t_data *g);
void	render_frame(t_data *img);
void	read_xpm(t_data *g);
void	coin_animation(t_data *img);
void	put_player(t_data *g);
void	player_animation(t_data *g);
void	player_animation_d(t_data *g);
void	player_animation_l(t_data *g);
void	player_animation_r(t_data *g);
void	player_animation_u(t_data *g);
void	floor_animation(t_data *g);
void	put_enemys(t_data *g);
void	enemy_animation(t_data *g);
void	move_enemy(t_data *g);
void	check_map_rules_part(t_data *img);
int		check_map_rules(t_data *img);
void	map_init(t_data *g);
void	err_init(t_data *img);
int		err_print(t_data *g);
int		close_win(t_data *g);
void	start(t_data *g);
int		buttons_hook(int key, t_data *g);
void	create_map(t_data *g);
void	game_moves_to_window(t_data *g);
long	current_time(t_data *g);
void	start_sound_thread(t_data *g);
void	*play_sound();
void	doll_animation_red(t_data *g);
void	doll_animation_green(t_data *g);

# define WALL			"textures/WALL.xpm"
# define WALL_L			"textures/walls/wall_3_2.xpm"
# define WALL_R			"textures/walls/wall_3_1.xpm"
# define WALL_U			"textures/walls/wall_3.xpm"
# define WALL_D			"textures/walls/wall_3_0.xpm"
# define CORNER_LU		"textures/walls/wall_edge_1.xpm"
# define CORNER_RU		"textures/walls/wall_edge_0.xpm"
# define CORNER_LD		"textures/walls/wall_edge_2.xpm"
# define CORNER_RD		"textures/walls/wall_edge_3.xpm"


# define FLOOR_GREEN	"textures/sand/sand_2.xpm"
# define FLOOR_RED		"textures/sand/sand_red_2.xpm"
# define FLOOR_TREE		"textures/sand/sand_2_with_tree.xpm"
# define FLOOR_TREE_RED	"textures/sand/sand_red_2_with_tree.xpm"

# define MONEY1		"textures/cookie/honey_3_0.xpm"
# define MONEY2		"textures/cookie/honey_3_1.xpm"
# define MONEY3		"textures/cookie/honey_3_2.xpm"
# define MONEY4		"textures/cookie/honey_3_3.xpm"
# define MONEY5		"textures/cookie/honey_3_4.xpm"
# define MONEY6		"textures/cookie/honey_3_5.xpm"
# define MONEY7		"textures/cookie/honey_3_6.xpm"

# define EXIT_GREEN	"textures/sand/sand_2_with_line.xpm"
# define EXIT_RED	"textures/sand/sand_red_2_with_line.xpm"

# define U_LOOSE		"textures/screens/loose_coffin_0.xpm"
# define U_WIN			"textures/screens/win_money_0.xpm"
# define START_SCREEN	"textures/screens/game_start.xpm"

# define PLAYER_D1	"textures/chel/fig_front_0.xpm"
# define PLAYER_D2	"textures/chel/fig_front_1.xpm"
# define PLAYER_D3	"textures/chel/fig_front_2.xpm"
# define PLAYER_D4	"textures/chel/fig_front_3.xpm"

# define PLAYER_L1	"textures/chel/fig_left_0.xpm"
# define PLAYER_L2	"textures/chel/fig_left_1.xpm"
# define PLAYER_L3	"textures/chel/fig_left_2.xpm"
# define PLAYER_L4	"textures/chel/fig_left_3.xpm"

# define PLAYER_U1	"textures/chel/fig_back_0.xpm"
# define PLAYER_U2	"textures/chel/fig_back_1.xpm"
# define PLAYER_U3	"textures/chel/fig_back_2.xpm"
# define PLAYER_U4	"textures/chel/fig_back_3.xpm"

# define PLAYER_R1	"textures/chel/fig_right_0.xpm"
# define PLAYER_R2	"textures/chel/fig_right_1.xpm"
# define PLAYER_R3	"textures/chel/fig_right_2.xpm"
# define PLAYER_R4	"textures/chel/fig_right_3.xpm"

# define ENEMY1		"textures/enemy/enemy_front_0.xpm"
# define ENEMY2		"textures/enemy/enemy_front_1.xpm"
# define ENEMY3		"textures/enemy/enemy_front_2.xpm"
# define ENEMY4		"textures/enemy/enemy_front_3.xpm"
# define ENEMY5		"textures/enemy/enemy_front_2.xpm"
# define ENEMY6		"textures/enemy/enemy_front_1.xpm"

# define DOLL_0		"textures/doll/doll_0.xpm"
# define DOLL_1		"textures/doll/doll_1.xpm"
# define DOLL_2		"textures/doll/doll_2.xpm"
# define DOLL_3		"textures/doll/doll_3.xpm"
# define DOLL_4		"textures/doll/doll_4.xpm"
# define DOLL_BODY	"textures/doll/body_0.xpm"
#endif
