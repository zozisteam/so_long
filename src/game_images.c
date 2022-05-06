/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:56:43 by apple             #+#    #+#             */
/*   Updated: 2022/05/06 22:32:57 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*start the window using mlx_init and mlx_new_win*/
void	start_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map.column * TILES;
	y = game->map.line * TILES;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
}

t_img	put_image(void *mlx)
{
	t_img	*img;

	img = NULL;
	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_WALL, &img->wall.size.x,
			&img->wall.size.y);
	img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EXIT, &img->exit.size.x,
			&img->exit.size.y);
	img->item.img = mlx_xpm_file_to_image(mlx, PATH_ITEM, &img->item.size.x,
			&img->item.size.y);
	img->pdown.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN,
			&img->pdown.size.x, &img->pdown.size.y);
	img->pup.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_UP,
			&img->pup.size.x, &img->pup.size.y);
	img->pleft.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_LEFT,
			&img->pleft.size.x, &img->pleft.size.y);
	img->pright.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN,
			&img->pright.size.x, &img->pright.size.y);
	return (*img);
}

void	print_player(t_game *game, int x, int y)
{
	if (game->side == DOWN)
		mlx_put_image_to_window(&game->mlx, &game->win,
			&game->img.pdown, x, y);
	if (game->side == UP)
		mlx_put_image_to_window(&game->mlx, &game->win,
			&game->img.pup, x, y);
	if (game->side == LEFT)
		mlx_put_image_to_window(&game->mlx, &game->win,
			&game->img.pleft, x, y);
	if (game->side == RIGHT)
		mlx_put_image_to_window(&game->mlx, &game->win,
			&game->img.pright, x, y);
}

//mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y).
//The (x , y) coordinates define where the image should be
//placed in the window.
void	print_sprites(t_game *game, int line, int column)
{
	int	x;
	int	y;

	x = column * TILES;
	y = line * TILES;
	if (game->map.map[line][column] == 'P')
		print_player(game, x, y);
	if (game->map.map[line][column] == '1')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.wall, x, y);
	if (game->map.map[line][column] == '0')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.emp, x, y);
	if (game->map.map[line][column] == 'E')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.exit, x, y);
	if (game->map.map[line][column] == 'C')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.item, x, y);
}

void	display_game_text(t_game *game)
{
	printf("Steps: %d\n", game->steps);
}
