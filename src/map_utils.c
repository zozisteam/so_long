/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:27:51 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 22:19:34 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* map_count_lines and map_count_columns */
/* both do it by using getnextline. valid member */
/* gets updated depending on if amount of lines */
/* make a valid map or not */
int	map_count_lines(char *path, t_map *map_struct)
{
	int	fd;
	int	linecount;

	fd = open(path, O_RDONLY);
	linecount = 0;
	while (get_next_line(fd))
		linecount++;
	map_struct->line = linecount;
	close(fd);
	if (linecount <= 0)
	{
		map_struct->valid = 0;
		return (0);
	}
	map_struct->valid = 1;
	return (linecount);
}

/* done by getting the first line in .ber file */
/* then cmp str_len with the rest of the lines */
/*  */
int	map_count_columns(char *path, t_map *map_struct)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 1;
	while (i < map_struct->line)
	{
		if (ft_strlen(line) != ft_strlen(get_next_line(fd)))
			return (error_msg("invalid map :( check map columns"));
		i++;
	}	
	map_struct->column = ft_strlen(line);
	map_struct->valid = 1;
	close(fd);
	return (ft_strlen(line));
}

/* mem allocation for map.map which will be returned */
/* done by counting lines and columns in .ber file */
char	**map_malloc(char *path, t_map *map_struct)
{
	char	**map;

	map_struct->line = map_count_lines(path, map_struct);
	map_struct->column = map_count_columns(path, map_struct);
	if (map_struct->valid <= 0)
		return (0); //invalid map
	if (map_struct->line <= 0)
		return (0); //error in map
	map = malloc(sizeof(char *) * map_struct->line + 1);
	if (!map)
		return (0); //map allocation error
	return (map);
}

void	player_starting_pos(t_map *map, int line, int col)
{
	map->check.player++;
	map->player.x = col;
	map->player.y = line;
}

int	valid_map_element(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}
