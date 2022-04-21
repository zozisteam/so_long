/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/21 06:05:43 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	initialize_game(&game);
	if (start_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_window, (void *)&game); //0->when destroy (3rd arg is useless)
	mlx_hook(game.win, 2, 0, action, (void *)&game); //2->when buttondown (check supported events and their corresponding number)
	mlx_loop_hook(game.mlx, update, &game); //when no event (function needs fixing)
	mlx_loop(game.mlx); //to wait for and recieve events
	return (0);
}
