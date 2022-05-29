/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:31:24 by apple             #+#    #+#             */
/*   Updated: 2022/05/29 14:01:56 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* The map must contain at least 1 exit, 1 collectible, and 1 
 starting position. */
int	verify_map_elements(t_map *map)
{
	if (map->exit < 1)
		return (error_msg("make sure there is at least 1 exit"));
	if (map->collect < 1)
		return (error_msg("make sure there is at least 1 collectible"));
	if (map->player_count == 0)
		return (error_msg("no player found"));
	if (map->player_count != 1)
		return (error_msg("only 1 player allowed"));
	return (1);
}

/* count significant members of map struct such as player, 
  collectibles, exits, and if the char within map 2d array 
  is valid or not by calling is_element_ok(). verify_mp_elem()
checks if the count of everything is in accordance with game rules */
int	count_map_elements(t_map *map)
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
			else if (map->map[line][col] == 'C')
				map->collect++;
			else if (map->map[line][col] == 'E')
				map->exit++;
			else if (!is_element_ok(map->map[line][col]))
				return (error_msg("illegal character in map"));
			col++;
		}
		line++;
	}
	return (verify_map_elements(map));
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
	if ((open (map_file, O_RDONLY) < 0))
		return (error_msg("not a valid file"));
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

/* int line parameter is 0 when its a middle line and 1 if first/last line */
int	check_walls_helper(char *map_line, int line)
{
	unsigned int	i;

	i = 0;
	if (line == 0)
	{
		if (map_line[0] != '1' || map_line[ft_strlen(map_line) - 1] != '1')
			return (0);
	}
	if (line == 1)
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

/* check walls function finds out if we're on the (first or ending lines)
  OR (middle lines). depending on which case it calls its helper function
  and passes the current line to check all '1's if its the first case OR 
  '1's only on edges of line if its the other case.*/
int	check_walls(t_map *map_struct)
{
	int	i;

	i = 0;
	while (i < map_struct->line)
	{
		if (i == 0 || i == map_struct->line - 1)
		{
			if (!check_walls_helper(map_struct->map[i], 1))
				return (error_msg("inavlid map :( check walls"));
		}
		else
			if (!check_walls_helper(map_struct->map[i], 0))
				return (error_msg("inavlid map :( check walls"));
		i++;
	}
	return (1);
}
