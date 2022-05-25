/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:55:34 by apple             #+#    #+#             */
/*   Updated: 2022/05/25 16:12:19 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* initialize the game struct to start game */
void	game_start_struct(t_game *game)
{
	game->side = 0;
	game->finish = 0;
	game->steps = 0;
	game->init_game = 0;
	game->side = DOWN;
}

void	map_start_struct(t_map *map)
{
	map->collect = 0;
	map->exit = 0;
	map->player_count = 0;
	map->column = 0;
	map->line = 0;
	map->valid = 1;
}

/* start game by creating t_map variable and initializing it */
/* to put it into game struct.. then open window and start printing*/
int	game_start(t_game *game, char **argv)
{
	t_map	map;

	map_start_struct(&map);
	game->map = map;
	if (!read_map(argv[1], &game->map))
		return (0);
	start_window(game);
	print_map(game);
	game->init_game = 1;
	return (1);
}
