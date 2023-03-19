/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:16:06 by prranges          #+#    #+#             */
/*   Updated: 2021/05/27 16:01:29 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	mem_check(char **mem, char **line)
{
	char	*p;
	int		x;

	x = 1;
	p = NULL;
	if (*mem)
	{
		p = ft_strchr(*mem, '\n');
		if (p)
		{
			x = 0;
			*p = '\0';
			*line = ft_strdup(*mem);
			ft_strcpy(*mem, ++p);
		}
		else
		{
			*line = ft_strdup(*mem);
			free(*mem);
			*mem = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (x);
}

void	new_line(char *buf, char **line)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
}

int	ret_check(char *mem, size_t r)
{
	if (mem || r)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	size_t		r;
	static char	*mem;
	char		*p;

	if (read(fd, NULL, 0) || BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	r = mem_check(&mem, line);
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		p = ft_strchr(buf, '\n');
		if (p)
		{
			*p = '\0';
			new_line(buf, line);
			mem = ft_strdup(++p);
			break ;
		}
		else
			new_line(buf, line);
	}
	return (ret_check(mem, r));
}
