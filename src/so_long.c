/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/10 16:15:33 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// #include "./game_images.c"
// #include "./game_key_hook.c"
// #include "./game_start.c"
// #include "./map_check.c"
// #include "./map_print.c"
// #include "./map_start.c"
// #include "./map_utils.c"
// #include "../libft/ft_printf.c"
// #include "../libft/get_next_line_utils.c"
// #include "../libft/get_next_line.c"


int	main(int argc, char **argv)
{
	t_game	game;

	game_start_struct(&game);
	if (game_start(&game, argc, argv) < 0) //game has been started and window is there..
		return (0);
	mlx_hook(game.win, 17, 0, close_window, (void *)&game); //0->when destroy (3rd arg is useless)
	mlx_hook(game.win, 2, 0, key_event_handler, (void *)&game); //2->when buttondown (check supported events and their corresponding number)
	//mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx); //to wait for and recieve events
	return (0);
}
