/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:43:15 by prranges          #+#    #+#             */
/*   Updated: 2021/05/14 09:44:54 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *gde, const char *chto, size_t len)
{
	size_t	g_len;
	size_t	c_len;

	g_len = 0;
	if (chto[0] == '\0')
		return ((char *)gde);
	if (!*gde)
		return (0);
	while (g_len < len)
	{
		if (gde[g_len] == chto[0])
		{
			c_len = 1;
			while (gde[g_len + c_len] == chto[c_len]
				&& (g_len + c_len) < len && chto[c_len] != '\0')
				++c_len;
			if (chto[c_len] == '\0')
				return ((char *)&gde[g_len]);
		}
		g_len++;
	}
	return (0);
}
