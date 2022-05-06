/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:13:44 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 19:39:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = (size_t)ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{
			if (*src != '\0')
			{
				*dst++ = *src++;
			}
			else
				break ;
			i++;
		}
		*dst = '\0';
	}
	return (len);
}
