/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:51:58 by prranges          #+#    #+#             */
/*   Updated: 2021/05/13 10:32:22 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s1_len;
	size_t	x;

	x = 0;
	if (!s1)
		return (0);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (ft_strdup(""));
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	res = ft_substr(s1, 0, s1_len + 1);
	return (res);
}
