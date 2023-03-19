/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:42:22 by prranges          #+#    #+#             */
/*   Updated: 2021/10/07 10:44:27 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char *file)
{
	int		fd;
	int		counter;
	char	c;

	counter = 3;
	fd = open(file, O_RDONLY);
	if (fd == -1 || map_ber_check(file))
	{
		if (fd == -1)
			ft_putstr_fd("Error\nCan't read the map.\n", 1);
		if (map_ber_check(file) && fd != -1)
			ft_putstr_fd("Error\nMap file must be with the .ber extension.\n", 1);
		exit (1);
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

void	create_map(t_data *g)
{
	int			i;
	int			fd;
	static int	t;

	g->map.rows = count_rows(g->file_name);
	fd = open(g->file_name, O_RDONLY);
	i = -1;
	if (t++ == 0)
		g->map.map = malloc(sizeof(char *) * g->map.rows);
	while (get_next_line(fd, &g->map.map[++i]))
		;
	g->map.map[++i] = NULL;
	close(fd);
}
