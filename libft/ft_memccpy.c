/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:56:20 by prranges          #+#    #+#             */
/*   Updated: 2021/04/26 17:44:38 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		ctmp;
	unsigned char		*dsttmp;
	const unsigned char	*srctmp;

	ctmp = (unsigned char)c;
	dsttmp = (unsigned char *)dst;
	srctmp = (const unsigned char *)src;
	i = 0;
	while (i < len)
	{
		*(dsttmp + i) = *(srctmp + i);
		if (srctmp[i] == ctmp)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
