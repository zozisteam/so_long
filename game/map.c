/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/04/21 06:29:27 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map, t_map *o_map)
{
	int i;

	i = 0;
	while (i <= o_map->line)
		free(map[i++]);
	free(map);
}

void init_map0(t_map *map)
{
	//initialize zeros
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;
	map->end_col = 0;
	map->column = 0;
	//map->item_bup = 0;
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
	int	fd;
	int	linecount;

	fd = open(path, O_RDONLY);
	linecount = 0;
	while (getnextline(fd))
		linecount++;
	o_map->line = linecount;
	close(fd);
	if (linecount <= 0)
	{
		o_map->valid = 0;
		return (0);
	}
	o_map->valid = 1;
	return (linecount);
}

int	count_len(char *path, t_map *o_map)
{
	int	fd;
	int	lencount;
	char *line;
	int i;
	int valid;

	fd = open(path, O_RDONLY);
	lencount = 0;
	valid = 1;
	line = get_next_line(fd);
	i = 0;
	while(i < o_map->line)
	{
		if (ft_strlen(line) != ft_strlen(get_next_line(fd)))
			valid = 0;
		if (i == (o_map->line - 1) && ft_strlen(line) == (ft_strlen(get_next_line(fd) - 1)))
			valid = 1;
		i++;
	}
	if (valid == 0)
	{
		ft_printf("invalid map\n");
		return (0);
	}
	o_map->column = ft_strlen(line);
	o_map->valid = 0;
	close(fd);
	return (ft_strlen(line));
}

/* Allocates n space in the memory for a array with lines  */
static char	**map_malloc(char *path, t_map *o_map)
{
	char	**map;

	o_map->line = count_lines(path, o_map);
	o_map->column = count_len(path, o_map);
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
	int		i;

	map = map_malloc(path, o_map);
	if(!map)
		return (0);
	lines = 0;
	i = 0;
	file = open(path, O_RDONLY);
	//count how many lines (loop gnl and update lines)
	while (i < o_map->line)
	{
		map[i] = get_next_line(file);
		i++;
	}
	map[i] = NULL;
	check_walls(map, o_map);
	//do i need backup map? if so do it here
	if (o_map->valid == 0)
	{
		free_map(**map, o_map);
		printf("Error\n		Invalid map\n");
		return (0);
	}
	close(file);
	return (map);
}
