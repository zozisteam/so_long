/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:55:34 by apple             #+#    #+#             */
/*   Updated: 2022/04/17 20:53:01 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



/* Init the window of game */
void	init_window(t_game *game)
{
	int x;
	int y;

	x = game->map.column * TILES;
	y = game->map.line * TILES;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
}



/* Init the game starting the window and the map */
int	init_game(t_game *game, int argc, char **argv)
{
	t_map	map;

	init_map0(&map); //pass as an address &
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (-1);
	init_window(game);
	game->img = init_image(game->mlx);
	game->side = DOWN;
	print_map(game);
	game->init_game = 1;
	return (1);
}

/*(inside init_game() -call-> init_map0 to initialize all zeros for
map then we init_map and -call-> valid_map() to check before
-call-> read_map() which allocates mem for **map using -call->
map_malloc() */