/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:24 by apple             #+#    #+#             */
/*   Updated: 2022/04/20 19:48:59 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* check argc and the map extension */
int	valid_map(int argc, char *map_file)
{
	if (argc == 1)
	{
		printf(" Error\n    No map file\n");
		return (0);
	}
	if (check_extension(map_file, ".ber") <= 0)
	{
		printf("Wrong file extension\n    No map file\n");
		return (0);
	}
		if (argc > 2)
	{
		printf("Warning\n Only first file will be used\n");
	}
	return (1);
}

int check_walls_sides(char *map, t_map *o_map)
{
	if (map[0] == '1' && map[ft_strlen(map) - 1] == '1')
		return (1);
	return (0);
}

int check_walls(char **map, t_map *o_map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < o_map->line)
	{
		if (i == 0 || i == o_map->line - 1) //if first or last line
		{
			j = 0;
			while(j < o_map->column)
			{
				if (map[i][j] != '1')
				{
					o_map->valid = 0;
					printf("Invalid map\n");
					return (0);
				}
				j++;
			}
		}
		else
			if (!check_walls_sides(map[i], o_map)) // if middle lines
				return (0);
		i++;
	}
	o_map->valid = 1;
	return (1);
}