/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:50:59 by prranges          #+#    #+#             */
/*   Updated: 2021/10/07 15:51:02 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_ber_check(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (argv[len - 4] == '.')
		if (argv[len - 3] == 'b')
			if (argv[len - 2] == 'e')
				if (argv[len - 1] == 'r')
					return (0);
	return (1);
}
