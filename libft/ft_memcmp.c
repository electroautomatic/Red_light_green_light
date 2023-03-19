/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:58:03 by prranges          #+#    #+#             */
/*   Updated: 2021/04/26 17:11:36 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t len)
{
	unsigned char	*srctmp1;
	unsigned char	*srctmp2;
	size_t			i;

	srctmp1 = (unsigned char *)src1;
	srctmp2 = (unsigned char *)src2;
	i = 0;
	while (i < len)
	{
		if (srctmp1[i] == srctmp2[i])
			i++;
		else
			return (srctmp1[i] - srctmp2[i]);
	}
	return (0);
}
