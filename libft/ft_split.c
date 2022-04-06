/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:59:42 by alalmazr          #+#    #+#             */
/*   Updated: 2021/11/30 12:32:01 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	getnextstr(char **nextstr, unsigned int *nextstr_len, char c)
{
	unsigned int	i;

	*nextstr += *nextstr_len;
	*nextstr_len = 0;
	i = 0;
	while (**nextstr && **nextstr == c)
		(*nextstr)++;
	while ((*nextstr)[i] != '\0' && (*nextstr)[i] != c)
	{
		(*nextstr_len)++;
		i++;
	}
	return ;
}

static unsigned int	wordcount(char const *str, char delimeter)
{
	int	flag;
	int	wordnb;

	flag = 0;
	wordnb = 0;
	while (*str)
	{
		if (*str != delimeter && flag == 0)
		{
			wordnb++;
			flag = 1;
		}
		else if (*str == delimeter)
			flag = 0;
		str++;
	}
	return ((unsigned int)wordnb);
}

char	**ft_split(char const *string, char delimeter)
{
	char			**split;
	char			*nextstr;
	unsigned int	nextstr_len;
	unsigned int	wordnb;
	unsigned int	i;

	i = 0;
	wordnb = wordcount(string, delimeter);
	split = (char **)malloc((wordnb + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	nextstr = (char *)string;
	nextstr_len = 0;
	while (i < wordnb)
	{
		getnextstr(&nextstr, &nextstr_len, delimeter);
		split[i] = (char *)malloc(sizeof(char) * (nextstr_len + 1));
		if (!split[i])
			return (NULL);
		ft_strlcpy(split[i], nextstr, nextstr_len + 1);
		i++;
	}
	split[i] = NULL;
	return (split);
}

// int main()
// {

// 	 char * * grid = ft_split("     ", ' ');

// 	return 0;
// }