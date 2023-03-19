/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:42:11 by prranges          #+#    #+#             */
/*   Updated: 2021/09/19 12:59:30 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*play_doll_sound(void *g)
{
	t_data *ptr = (t_data *)g;
	
	while (1)
	{
		if (ptr->doll_head_sound > 0)
		{
			ptr->doll_head_sound = 0;
			system("afplay sound/head_move.mp3");
		}
		usleep(30);
	}
	return (0);
}

void	*play_red_light_sound(void *g)
{
	t_data *ptr = (t_data *)g;
	while (1)
	{
		if (ptr->red_light_sound > 0)
		{
			ptr->red_light_sound = 0;
			system("afplay sound/red_light_01.mp3");
		}
		usleep(30);
	}
}

void	*play_green_light_sound(void *g)
{
	t_data *ptr = (t_data *)g;
	while (1)
	{
		if (ptr->green_light_sound > 0)
		{
			ptr->green_light_sound = 0;
			system("afplay sound/green_light_01.mp3");
		}
		usleep(30);
	}
}

void	*play_start_sound(void *g)
{
	t_data *ptr = (t_data *)g;
	
	while (1)
	{
		if (ptr->start_menu_sound > 0)
		{
			ptr->start_menu_sound = 0;
			system("afplay sound/start_menu_sound_short.mp3");
		}
		if (ptr->start_game)
			break;
		usleep(30);
	}
	return (0);
}

void	*play_sound(void *g)
{
	t_data *ptr = (t_data *)g;
	
	while (1)
	{
		if (ptr->c.c_sound > 0)
		{
			ptr->c.c_sound = 0;
			system("afplay sound/coin.mp3");
		}
		if (ptr->loose_sound > 0)
		{
			ptr->loose_sound = 0;
			system("afplay sound/loose.mp3");
		}
		if (ptr->win_sound > 0)
		{
			ptr->win_sound = 0;
			system("afplay sound/win.mp3");
		}
		usleep(30);
	}
	return (NULL);
}

void	start_sound_thread(t_data *g)
{
	pthread_t	sound;
	pthread_t	start_sound;
	pthread_t	doll_sound;
	pthread_t	red_light_sound;
	pthread_t	green_light_sound;
	
	pthread_create(&sound, NULL, play_sound, g);
	pthread_create(&start_sound, NULL, play_start_sound, g);
	pthread_create(&doll_sound, NULL, play_doll_sound, g);
	pthread_create(&red_light_sound, NULL, play_red_light_sound, g);
	pthread_create(&green_light_sound, NULL, play_green_light_sound, g);
	pthread_detach(sound);
	pthread_detach(start_sound);
	pthread_detach(doll_sound);
	pthread_detach(red_light_sound);
	pthread_detach(green_light_sound);
}
