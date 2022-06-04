/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:04:55 by alalmazr          #+#    #+#             */
/*   Updated: 2022/06/04 11:04:02 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( void *s1, void *s2, size_t n)
{
	unsigned char		*pdst;
	unsigned char		*psrc;
	size_t				i;

	i = 0;
	pdst = (unsigned char *)s1;
	psrc = (unsigned char *)s2;
	while (i < n)
	{
		if (pdst[i] != psrc[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (pdst[i] - psrc[i]);
}
