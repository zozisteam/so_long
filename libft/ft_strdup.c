/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:33:14 by alalmazr          #+#    #+#             */
/*   Updated: 2021/11/30 12:31:17 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*x;
	int		i;

	i = 0;
	x = (char *)malloc(ft_strlen(src) + 1);
	if (!x)
		return (NULL);
	while (src[i] != '\0')
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
