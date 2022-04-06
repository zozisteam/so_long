/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:05:02 by alalmazr          #+#    #+#             */
/*   Updated: 2022/03/25 14:07:07 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}
