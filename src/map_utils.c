/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:27:51 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/24 11:47:24 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* map_count_lines and map_count_columns */
/* both do it by using getnextline. valid member */
/* gets updated depending on if amount of lines */
/* make a valid map or not */
int	map_count_lines(t_map *map_struct)
{
	int	i;

	i = 0;
	while (map_struct->map[i])
		i++;
	map_struct->line = i;
	if (i <= 0)
	{
		map_struct->valid = 0;
		return (0);
	}
	return (i);
}

/* done by getting the first line in .ber file */
/* then cmp str_len with the rest of the lines */
/*  */
int	map_count_columns(t_map *map_struct)
{
	int		i;

	i = 0;
	while (i < map_struct->line)
	{
		if (ft_strlen(map_struct->map[0]) != ft_strlen(map_struct->map[i]))
			return (error_msg("invalid map :( check map columns", map_struct));
		i++;
	}	
	map_struct->column = ft_strlen(map_struct->map[0]);
	return (map_struct->column);
}

void	player_starting_pos(t_map *map, int line, int col)
{
	map->player_count++;
	map->player.x = col;
	map->player.y = line;
}

int	valid_map_element(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}
