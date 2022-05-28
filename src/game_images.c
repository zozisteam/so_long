/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:56:43 by apple             #+#    #+#             */
/*   Updated: 2022/05/27 10:09:14 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* start the window using mlx_init and mlx_new_win */
void	start_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map.column * TILES;
	height = game->map.line * TILES;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

//mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y).
//The (x , y) coordinates define where the image should be
//placed in the window.
void	put_image(t_game *game, char *path, int line, int col)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = 0;
	height = 0;
	x = col * TILES;
	y = line * TILES;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

/* print the player pic according to which side he is facing */
void	put_player_tile(t_game *game, int line, int col)
{
	if (game->side == DOWN)
		put_image(game, PATH_PLAYER_DOWN, line, col);
	if (game->side == UP)
		put_image(game, PATH_PLAYER_UP, line, col);
	if (game->side == LEFT)
		put_image(game, PATH_PLAYER_LEFT, line, col);
	if (game->side == RIGHT)
		put_image(game, PATH_PLAYER_RIGHT, line, col);
}
