/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/05/10 14:36:28 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_start_struct(t_map *map)
{
	map->collect = 0;
	map->exit = 0;
	map->player_count = 0;
	map->column = 0;
	map->line = 0;
	map->valid = 1;
}

/* check argc and the map extension */
int	check_args(int argc, char *map_file)
{
	if (argc == 1)
		return (error_msg("no map file :(", 0));
	if (check_extension(map_file, ".ber") == 0)
		return (error_msg("wrong file extension :( no map file", 0));
	if (argc > 2)
		ft_printf("warning\nonly first file will be used\n");
	return (1);
}

/* read the map by gnl and storing it into **map */
/* then we check the walls of the map for '1's */
char	**read_map(char *path, t_map *map_struct)
{
	int		fd;
	char	**map;
	int		i;

	map = NULL;
	map_malloc(map, path, map_struct);
	if (!map)
		return (0);
	i = 0;
	fd = open(path, O_RDONLY);
	while (i < map_struct->line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	check_walls(map, map_struct);
	if (!map_struct->valid)
	{
		free_map(map, map_struct);
		error_msg("invalid map :(", map_struct);
		return (0);
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
		return (0);
	map = read_map(argv[1], &game->map);
	if (!map)
		return (0);
	return (map);
}
