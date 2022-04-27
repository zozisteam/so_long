/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/27 05:38:20 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_start_struct(&game);
	if (start_game(&game, argc, argv) < 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_window, (void *)&game); //0->when destroy (3rd arg is useless)
	mlx_hook(game.win, 2, 0, key_event_handler, (void *)&game); //2->when buttondown (check supported events and their corresponding number)
	mlx_loop(game.mlx); //to wait for and recieve events
	//mlx_loop_hook for if enemy touches player
	return (0);
}
// consider***
// if ((ft_strchr(whole_chars, 'P') == NULL)
// 		|| (ft_strchr(whole_chars, 'E') == NULL)
// 		|| (ft_strchr(whole_chars, 'C') == NULL))
// 		error()