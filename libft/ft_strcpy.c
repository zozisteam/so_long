/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:03:05 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/15 11:12:39 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char*	ft_strcpy(char* dest, char* src)
{
	char *ptr;
	
	if (!dest)
        return (0);
	ptr = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
	*dest = '\0';
	return ptr;
}