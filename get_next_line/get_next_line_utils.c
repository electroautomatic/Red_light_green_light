/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:18:29 by prranges          #+#    #+#             */
/*   Updated: 2021/05/18 11:24:38 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		res[x] = s2[y];
		x++;
		y++;
	}
	res[x] = '\0';
	return (res);
}

char	*ft_strchr(const char *src, int c)
{
	while (*src)
	{
		if (*src++ == (char)c)
			return ((char *)src - 1);
	}
	if (c == '\0')
		return ((char *)src);
	return (NULL);
}

char	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (*dst);
}
