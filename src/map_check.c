/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:24 by apple             #+#    #+#             */
/*   Updated: 2022/05/22 00:57:58 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_elements(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (map->map[line])
	{
		col = 0;
		while (map->map[line][col])
		{
			if (map->map[line][col] == 'P')
				player_starting_pos(map, line, col);
			if (map->map[line][col] == 'C')
				map->collect++;
			if (map->map[line][col] == 'E')
				map->exit++;
			if (!valid_map_element(map->map[line][col]))
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

int	verify_elements(t_map *map)
{
	if (map->exit < 1)
		return(error_msg("make sure there is at least 1 exit", map));
	if (map->collect < 1)
		return(error_msg("make sure there is at least 1 collectible", map));
	if (map->player_count != 1)
		return(error_msg("only 1 player allowed", map));
	return (1);
}

/*check extension of map file with ".ber" which is 4 char long
check from len(file) - 4 (which should give last 4 char that
should == ".ber" in the end)*/
int	check_extension(char *map_file, char *ext)
{
	int		file_len;
	int		offset;
	size_t	i;

	i = 0;
	file_len = ft_strlen(map_file);
	offset = file_len - ft_strlen(ext);
	if (file_len > 4)
	{
		while (i < ft_strlen(ext) && map_file[i + offset] != '\0')
		{
			if (map_file[i + offset] != ext[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	check_walls_helper(char *map_line, int line)
{
	unsigned int	i;

	i = 0;
	if (line == 0) //middle lines
	{
		if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
			return (0);
	}
	if (line == 1) //first/last line
	{
		while (i < ft_strlen(map_line))
		{
			if (map_line[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_walls(t_map *map_struct)
{
	int	i;

	i = 0;
	while (i < map_struct->line)
	{
		if (i == 0 || i == map_struct->line - 1) //if first or last line
		{
			if (!check_walls_helper(map_struct->map[i], 1))
				return (error_msg("inavlid map :( check walls", map_struct));
		}
		else
			if (!check_walls_helper(map_struct->map[i], 0)) // if middle lines
				return (error_msg("inavlid map :( check walls", map_struct));
		i++;
	}
	return (1);
}
