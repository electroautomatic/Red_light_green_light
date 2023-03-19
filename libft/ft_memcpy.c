/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:56:00 by prranges          #+#    #+#             */
/*   Updated: 2021/05/07 12:24:22 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dsttmp;
	const char	*srctmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	dsttmp = (char *)dst;
	srctmp = (const char *)src;
	i = 0;
	while (i < len)
	{
		*(dsttmp + i) = *(srctmp + i);
		i++;
	}
	return (dst);
}
