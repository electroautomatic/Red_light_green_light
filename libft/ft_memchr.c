/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:57:37 by prranges          #+#    #+#             */
/*   Updated: 2021/04/26 17:14:25 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		ctmp;
	const unsigned char	*srctmp;

	ctmp = (unsigned char)c;
	srctmp = (const unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (srctmp[i] == ctmp)
			return ((void *)src + i);
		i++;
	}
	return (0);
}
