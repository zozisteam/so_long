/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:29:33 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 19:39:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	printfprocess( char *format, va_list args,
							int *res, int *i)
{
	if (format[*i] == '%')
		ft_putchar('%', res);
	if (format[*i] == 'c')
		ft_putchar((char)va_arg(args, int), res);
	if (format[*i] == 's')
		ft_putstr(va_arg(args, char *), res);
	if (format[*i] == 'p')
	{
		ft_putstr("0x", res);
		ft_hexconv(va_arg(args, unsigned int long), 'x', res);
	}
	if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(args, int), res);
	if (format[*i] == 'u')
		ft_putnbru(va_arg(args, unsigned int), res);
	if (format[*i] == 'x' || format[*i] == 'X')
		ft_hexconv(va_arg(args, unsigned int), format[*i], res);
}

int	ft_printf( char *format, ...)
{
	va_list	args;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start (args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			printfprocess(format, args, &res, &i);
		}
		else
			ft_putchar(format[i], &res);
		 i++;
	}
	va_end (args);
	return (res);
}
