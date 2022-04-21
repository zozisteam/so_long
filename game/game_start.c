/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:55:34 by apple             #+#    #+#             */
/*   Updated: 2022/04/21 06:21:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_game(t_game *game)
{
	game->side = 0;
	//game->reset = 0;
	game->end_game = 0;
	game->steps = 0;
	game->init_game = 0;
}

/* Init the map if is valid and store in a char **map */
char	**start_map(t_game *game, int argc, char **argv)
{
	char **map;

	if(!valid_map(argc, argv[1]))
		return (0);
	map = read_map(argv[1], &game->map);
	if (!map)
	{
		printf("invalid map\n");
		return (0);
	}
	return (map);
}

/* Init the window of game */
void	start_window(t_game *game)
{
	int x;
	int y;

	x = game->map.column * TILES;
	y = game->map.line * TILES;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
}



/* Init the game starting the window and the map */
int	start_game(t_game *game, int argc, char **argv)
{
	t_map	map;

	init_map0(&map); //pass as an address &
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (-1);
	start_window(game);
	game->img = put_image(game->mlx);
	game->side = DOWN;
	print_map(game);
	game->init_game = 1;
	return (1);
}

/*(inside init_game() -call-> init_map0 to initialize all zeros for
map then we init_map and -call-> valid_map() to check before
-call-> read_map() which allocates mem for **map using -call->
map_malloc() */