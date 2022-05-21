/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:45 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/21 22:56:12 by alalmazr         ###   ########.fr       */
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

//declare game struct then initialize to 0's
//check game_start if 1 then started and window is there..
//mlxhook (check supported events and their corresponding number)
//mlxhook--> 0->when destroy (3rd arg is useless)
//mlxhook--> 2->when buttondown
//mlxloop--> to wait for and recieve events
int	main(int argc, char **argv)
{
	t_game	game;

	if(!check_args(argc, argv[1]))
		return (0);
	game_start_struct(&game);
	if (game_start(&game, argc, argv) == 0)
		return (0);
	mlx_hook(game.win, 17, 0, close_window, (void *)&game);
	mlx_hook(game.win, 2, 0, key_event_handler, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
//mlx_loop_hook(game.mlx, update, (void *)&game);
