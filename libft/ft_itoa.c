/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:45:03 by alalmazr          #+#    #+#             */
/*   Updated: 2021/11/30 13:01:58 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	countdigit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static	void	process(char *itoa, int *n, int *i, int *size)
{
	while (*n >= 10)
	{
		itoa[*size] = *n % 10 + '0';
		*n = *n / 10;
		*i = *i + 1;
		*size = *size - 1;
	}
	if (*n < 10)
	{
		itoa[*size] = *n % 10 + '0';
		*i = *i + 1;
		*size = *size - 1;
	}
	itoa[*i] = '\0';
}

char	*process1(char *itoa, int *size)
{
	ft_strlcpy(&itoa[1], "2147483648", *size + 1);
	return (itoa);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*itoa;
	int		i;

	i = 0;
	size = countdigit(n);
	if (n < 0)
		itoa = (char *)malloc(size + 2);
	else
		itoa = (char *)malloc(size + 1);
	if (!itoa)
		return (NULL);
	if (n < 0)
	{	
		itoa[i] = '-';
		if (n == -2147483648)
			return (process1(itoa, &size));
		n = n * -1;
		i++;
	}
	else
		size--;
	process(itoa, &n, &i, &size);
	return (itoa);
}
