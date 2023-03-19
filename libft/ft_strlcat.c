/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:00:26 by prranges          #+#    #+#             */
/*   Updated: 2021/05/12 14:28:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	char			*dsttmp;
	const char		*srctmp;
	size_t			i;
	size_t			dstlen;

	dsttmp = dst;
	srctmp = src;
	i = len;
	while (i-- != 0 && *dst != '\0')
		dst++;
	dstlen = dst - dsttmp;
	i = len - dstlen;
	if (i-- == 0)
		return (dstlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (i != 0)
		{
			*dst++ = *src;
			i--;
		}
		src++;
	}
	*dst = '\0';
	return (dstlen + (src - srctmp));
}
