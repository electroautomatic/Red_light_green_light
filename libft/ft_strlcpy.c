/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:59:57 by prranges          #+#    #+#             */
/*   Updated: 2021/05/12 14:15:45 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	if (len > 0)
	{
		while ((len - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
			len--;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
