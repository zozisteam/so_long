/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:55:34 by apple             #+#    #+#             */
/*   Updated: 2022/05/21 22:49:38 by alalmazr         ###   ########.fr       */
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
}

/* start game by creating t_map variable and initializing it */
/* to put it into game struct.. then open window and start printing*/
int	game_start(t_game *game, int argc, char **argv)
{
	t_map	map;

	map_start_struct(&map);
	game->map = map;
	if(!read_map(argv[1], &map))
		return (0);
	start_window(game);
	game->img = put_image(game->mlx);
	game->side = DOWN;
	print_map(game);
	game->init_game = 1;
	return (1);
}
