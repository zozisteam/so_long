/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/14 16:41:54 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->side = 0;
	game->reset = 0;
	game->end_game = 0;
	game->steps = 0;
	game->init_game = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	start_game(&game);
	if (init_game(&game, argc, argv) < 0)
		return (0);
	//mlx_hook(game.win, 17, 0, close_win, (void *)&game);
	//mlx_hook(game.win, 2, 1L << 0, action, (void *)&game);
	//mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
