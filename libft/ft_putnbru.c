/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:02:00 by alalmazr          #+#    #+#             */
/*   Updated: 2022/03/25 14:07:02 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbru(unsigned int nb, int *count)
{
	if (nb > 9)
		ft_putnbru(nb / 10, count);
	return (ft_putchar(nb % 10 + '0', count));
}
