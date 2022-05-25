/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:42:03 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/26 00:49:59 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_tile(t_game *game, int line, int col)
{
	if (game->map.map[line][col] == '1')
		put_image(game, PATH_WALL, line, col);
	if (game->map.map[line][col] == '0')
		put_image(game, PATH_EMPTY, line, col);
	if (game->map.map[line][col] == 'P')
	{
		put_image(game, PATH_EMPTY, line, col);
		put_player_tile(game, line, col);
	}
	if (game->map.map[line][col] == 'E')
	{
		put_image(game, PATH_EMPTY, line, col);
		put_image(game, PATH_EXIT, line, col);
	}
	if (game->map.map[line][col] == 'C')
	{
		put_image(game, PATH_EMPTY, line, col);
		put_image(game, PATH_ITEM, line, col);
	}
}

/* print each tile depending on the char in map */
/* coordinates if 'P' or 'C' or 'E' and etc ... */
void	print_map(t_game *game)
{
	int		line;
	int		col;

	line = 0;
	while (game->map.map[line])
	{
		col = 0;
		while (game->map.map[line][col])
		{
			put_tile(game, line, col);
			col++;
		}
		line++;
	}
}
