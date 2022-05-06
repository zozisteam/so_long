/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:39:11 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 19:39:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( char *str, int c)
{
	int	end;

	end = ft_strlen(str);
	while (end >= 0)
	{
		if (str[end] == (char)c)
			return ((char *)str + end);
		end--;
	}
	return (NULL);
}
