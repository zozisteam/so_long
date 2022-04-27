/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:24 by apple             #+#    #+#             */
/*   Updated: 2022/04/27 06:55:13 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check(t_map *map)
{
	int line;
	int col;

	line = 0;
	while (map->map[line][0] != 0)
	{
		col = 0;
		while (map->map[line][col] != 0 && map->map[line][col] != '\n')
		{
			if (map->map[line][col] == 'P')
				map_player(&map, line, col);
			if (map->map[line][col] == 'C')
				map->check.collect++;
			if (map->map[line][col] == 'E')
				map->check.exit++;
			if (!valid_map_char(map->map[line][col]))
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

int verify(t_map *map)
{
	int valid;

	valid = 1;
	if (map->check.exit < 1)
		valid -= error_msg("at least 1 exit");
	if (map->check.collect < 1)
		valid -= error_msg("at least 1 collectible");
	if (map->check.player != 1)
		valid -= error_msg("only 1 player pos allowed");
	return (valid);
}

/* check argc and the map extension */
int	check_args(int argc, char *map_file)
{
	if (argc == 1)
		return (error_msg("no map file :("));
	if (check_extension(map_file, ".ber") <= 0)
		return (error_msg("wrong file extension :( no map file"));
	if (argc > 2)
		ft_printf("warning\nonly first file will be used\n");
	return (1);
}

int check_walls_helper(char *map_line, int specifier)
{
	int i;

	i = 0;
	if (specifier == 0) //middle line
	{
		if (map_line[0] != '1' && map_line[ft_strlen(map_line) - 1] != '1')
			return (0);
	}
	if (specifier == 1) //first/last line
	{
		while (i < ft_strlen(map_line))
		{
			if (map_line[i] != '1')
				return (0);
		}
	}
	return (1);
}

int check_walls(char **map, t_map *map_struct)
{
	int	i;
	
	i = 0;
	while (i < map_struct->line)
	{
		if (i == 0 || i == map_struct->line - 1) //if first or last line
		{
			if (!check_walls_helper(map[i], 1))
				return (error_msg("inavlid map :( check walls"));
		}
		else
			if (!check_walls_helpper(map[i], 0)) // if middle lines
				return (error_msg("inavlid map :( check walls"));
		i++;
	}
	map_struct->valid = 1;
	return (1);
}