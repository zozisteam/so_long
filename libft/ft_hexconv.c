/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:28:09 by alalmazr          #+#    #+#             */
/*   Updated: 2022/03/25 14:07:22 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	hexconv(unsigned long nb, char specifier, int *count)
{
	int	remainder;

	remainder = 0;
	if (nb == 0)
		return ;
	else
	{
		remainder = nb % 16;
		hexconv(nb / 16, specifier, count);
	}
	if (remainder > 9)
	{
		if (specifier == 'X')
			ft_putchar(55 + remainder, count);
		else if (specifier == 'x')
			ft_putchar(87 + remainder, count);
	}
	else
		ft_putnbr(remainder, count);
}

void	ft_hexconv(unsigned long nb, char specifier, int *count)
{
	if (nb == 0)
		ft_putchar('0', count);
	else
		hexconv(nb, specifier, count);
}
