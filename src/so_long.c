/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/06 19:07:52 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_start_struct(&game);
	if (start_game(&game, argc, argv) < 0) //game has been started and window is there..
		return (0);
	mlx_hook(game.win, 17, 0, close_window, (void *)&game); //0->when destroy (3rd arg is useless)
	mlx_hook(game.win, 2, 0, key_event_handler, (void *)&game); //2->when buttondown (check supported events and their corresponding number)
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx); //to wait for and recieve events
	return (0);
}
