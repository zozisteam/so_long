/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/05/05 03:47:28 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_start_struct(t_map *map)
{
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;
	map->end_col = 0;
	map->column = 0;
	map->line = 0;
	map->valid = 1;
}

/* read the map by gnl and storing it into **map */
/* then we check the walls of the map for '1's */
char	**read_map(char *path, t_map *map_struct)
{
	int		fd;
	char	**map;
	int		i;

	map = map_malloc(path, map_struct);
	if(!map)
		return (0);
	i = 0;
	fd = open(path, O_RDONLY);
	//count how many lines (loop gnl and update lines)
	while (i < map_struct->line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	check_walls(map, map_struct);
	if (map_struct->valid == 0)
	{
		free_map(**map, map_struct);
		return (error_msg("invalid map :("));
	}
	close(fd);
	return (map);
}

/* check if args are valid then read map into char **map */
/* to  start the map struct for game struct*/
char	**start_map(t_game *game, int argc, char **argv)
{
	char	**map;

	if (!check_args(argc, argv[1]))
		return (error_msg("invalid map :("));
	map = read_map(argv[1], &game->map);
	if (!map)
		return (error_msg("error in map creation"));
	return (map);
}