/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:51:38 by prranges          #+#    #+#             */
/*   Updated: 2021/05/12 16:01:59 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	const char	*srctmp;

	srctmp = src;
	while (*src)
		src++;
	while (src >= srctmp)
	{
		if (*src-- == (char)c)
			return ((char *)src + 1);
	}
	return (NULL);
}
