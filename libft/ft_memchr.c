/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:55:10 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 19:39:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)(((char *)s)[i]) == (unsigned char)c)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
