/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:50:10 by apple             #+#    #+#             */
/*   Updated: 2022/05/28 12:22:35 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* check argc and the map extension */
int	check_args(int argc, char *map_file)
{
	if (argc == 1)
		return (error_msg("no map file :("));
	if (check_extension(map_file, ".ber") == 0)
		return (error_msg("wrong file extension :( no map file"));
	if (argc > 2)
		ft_printf("warning\nonly first file will be used\n");
	return (1);
}

/* when reading map, if error occurs freeline() is used to prevent memleak */
void	freeline(char *map, char *line, int fd)
{
	if (map)
		free(map);
	free (line);
	close (fd);
}

/* chek that map has been read then split
the char *map by '\n' (bcz we used gnl to create
this unfisihed map str) and after splitting we have
the final map 2d array. we count lines, col, check and
verify elements, if we encounter any problem we return 0*/
int	is_map_ok(char *map, t_map *map_struct)
{
	if (!map || !map[0])
		return (0);
	map_struct->map = ft_split(map, '\n');
	if (!map_struct->map)
		return (0);
	if (!map_count_lines(map_struct))
		return (error_msg("line error"));
	if (!map_count_columns(map_struct))
		return (error_msg("column error"));
	if (!count_map_elements(map_struct))
		return (0);
	return (1);
}

/* read the map by gnl and storing it into char *map
by strjoining getnextline with *map to get all the
lines. then is_map_ok called to produce final cleaned
map and verifies it making sure its ok.*/
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
	return (is_map_ok(map, map_struct));
}
