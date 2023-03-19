/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:56:57 by prranges          #+#    #+#             */
/*   Updated: 2021/05/12 08:39:42 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dsttmp;
	const unsigned char	*srctmp;

	dsttmp = (unsigned char *)dst;
	srctmp = (const unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (srctmp < dsttmp)
	{
		while (len > 0)
		{
			dsttmp[len - 1] = srctmp[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		dsttmp[i] = srctmp[i];
		i++;
	}
	return (dst);
}
