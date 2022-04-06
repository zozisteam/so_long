/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:01:16 by alalmazr          #+#    #+#             */
/*   Updated: 2022/03/25 14:06:45 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar('8', count);
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-nb, count);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10, count);
		}
		ft_putchar(nb % 10 + '0', count);
	}
}
