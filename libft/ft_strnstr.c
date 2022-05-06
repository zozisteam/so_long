/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:30:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 21:26:31 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && (i + j) < len)
	{
		j = 0;
		while (big[i + j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (&(((char *)big)[i]));
			j++;
		}
		i++;
	}
	return (0);
}
