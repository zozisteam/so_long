/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/04/19 18:24:26 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/* check argc and the map extension */
int	valid_map(int argc, char *map_file)
{
	if (argc == 1)
	{
		printf("\033[31;1;4m" " Error\n    No map file\n" "\033[0m");
		return (0);
	}
	if (check_extension(map_file, ".ber") <= 0)
	{
		printf("\033[31;1;4m" " Wrong file extension\n    No map file\n" "\033[0m");
		return (0);
	}
		if (argc > 2)
	{
		printf("\033[0;33m" " Warning\n Only first file will be used\n" "\033[0m");
	}
	return (1);
}

void init_map0(t_map *map)
{
	//initialize zeros
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;
	map->end_col = 0;
	map->column = 0;
	map->item_bup = 0;
	map->line = 0;
	map->valid = 1;
}

/* check if map is valid, print error if any, if not initialize and store in **map */
char	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;

	if (!valid_map(argc, argv[1]))
	{
		printf("Error\n    Invalid map\n");
		return (0);
	}
	map = read_map(argv[1], &game->map);
	if (!map)
	{
		printf("Error\n    Error in creation of map\n");
		return (0);
	}
	return (map);
}

/* Return How many lines has the map */
/* This function use count function above. */
int	count_lines(char *path, t_map *o_map)
{
	int	file;
	int	count_lines;
	int	count_length;

	file = open(path, O_RDONLY);
	if (file < 0)
	{
		printf("Error\n    Error in file\n");
		return (0);
	}
	
	
}

/* Allocates n space in the memory for a array with lines  */
static char	**map_malloc(char *path, t_map *o_map)
{
	char	**map;

	o_map->line = count_lines(path, o_map);
	if (o_map->valid <= 0)
		return (0); //invalid map
	if (o_map->line <= 0)
		return (0); //error in map
	map = malloc(sizeof(char *) * o_map->line + 1);
	if (!map)
		return (0); //map allocation error
	return (map);
}

/* fill the array with the map 2d */
/* This function make a backup map for when a restart is requited */
/* The backup_map function  is in valid_maps.c file */
char	**read_map(char *path, t_map *o_map)
{
	int		file;
	int		lines;
	char	**map;

	map = map_malloc(path, o_map);
	lines = 0;
	file = open(path, O_RDONLY);
	//count how many lines (loop gnl and update lines)
	//check last line idk why
	//create a backup map (ignore it for now)
	//if invalid map->valid then free the map and return error invalid map
	close(file);
	return (map);
}
