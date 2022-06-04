/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:30:46 by alalmazr          #+#    #+#             */
/*   Updated: 2022/06/04 11:00:52 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;
	size_t	ret;

	ret = 0;
	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize == 0)
		return (slen);
	if (dstsize >= dlen)
		ret = slen + dlen;
	else
		ret = (slen + dstsize);
	while (i < (dstsize - dlen - 1) && src[i] != '\0' && dstsize > dlen)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (ret);
}
