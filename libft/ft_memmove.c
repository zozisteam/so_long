/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:09:07 by alalmazr          #+#    #+#             */
/*   Updated: 2021/11/30 12:32:31 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	const char		*psrc;
	unsigned int	i;

	i = 0;
	pdst = (char *)dst;
	psrc = (const char *)src;
	if (pdst > psrc)
	{
		while (len > 0)
		{
			pdst[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else if (pdst < psrc)
	{
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
