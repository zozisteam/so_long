/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/05/24 13:59:45 by alalmazr         ###   ########.fr       */
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

void	freeline(char *map, char *line, int fd)
{
	if (map)
		free(map);
	free (line);
	close (fd);
}

int	is_map_ok(char *map, t_map *map_struct)
{
	if (!map || !map[0])
		return (0);
	map_struct->map = ft_split(map, '\n');
	if (!map_struct->map)
		return (0);
	if (!map_count_lines(map_struct))
		return (0);
	if (!map_count_columns(map_struct))
		return (0);
	if (!check_elements(map_struct))
		return (0);
	if (!verify_elements(map_struct))
		return (0);
	return (1);
}

/* read the map by gnl and storing it into **map */
/* then we check the walls of the map for '1's */
int	read_map(char *path, t_map *map_struct)
{
	int		fd;
	char	*line;
	char	*map;

	fd = open (path, O_RDONLY);
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			freeline(map, line, fd);
			return (0);
		}
		map = ft_strjoin(map, line);
		free (line);
	}
	close(fd);
	if (!is_map_ok(map, map_struct))
		return (0);
	return (1);
}
