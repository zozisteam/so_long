/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:56:43 by apple             #+#    #+#             */
/*   Updated: 2022/04/27 05:21:36 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

t_img	put_image(void *mlx)
{
	t_img *img; //make sure this as a pointer is working or t_img img;

	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_WALL, &img->wall.size.x, &img->wall.size.y);//decrease variable sizes in naming
	//img->wall.bpp = mlx_get_data_addr(img->wall.img, &img->wall.bpp, &img->wall.line_size, &img->wall.endian);
	img->emp.img = mlx_xpm_file_to_image(mlx, PATH_EMPTY, &img->emp.size.x, &img->emp.size.y);
	img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EXIT, &img->exit.size.x, &img->exit.size.y);
	img->item.img = mlx_xpm_file_to_image(mlx, PATH_ITEM, &img->item.size.x, &img->item.size.y);
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN, &img->player.down.size.x, &img->player.down.size.y);
	img->player.left.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_LEFT, &img->player.left.size.x, &img->player.left.size.y);
	img->player.up.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_UP, &img->player.up.size.x, &img->player.up.size.y);
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN, &img->player.down.size.x, &img->player.down.size.y);
	return (*img);
}

void	print_player(t_game *game, int x, int y)
{
	if (game->side == DOWN)
			mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.down, x, y);
		if (game->side == UP)
			mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.up, x, y);
		if (game->side == LEFT)
			mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.left, x, y);
		if (game->side == RIGHT)
			mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.right, x, y);
}

//mlx_put_image_to_window(mlx_ptr, win_ptr, img, x, y).
//The (x , y) coordinates define where the image should be
//placed in the window.
void	print_sprites(t_game *game, int line, int column)
{
	int x;
	int y;

	x = column * TILES;
	y = line * TILES;
	if (&game->map.map[line][column] == 'P')
		print_player(game, x, y);
	if (&game->map.map[line][column] == '1')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.wall, x, y);
	if (&game->map.map[line][column] == '0')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.emp, x, y);
	if (&game->map.map[line][column] == 'E')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.exit, x, y);
	if (&game->map.map[line][column] == 'V')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.enemy, x, y);
	if (&game->map.map[line][column] == 'C')
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.item, x, y);
}

void display_game_text(t_game *game)
{
	mlx_string_put(&game->mlx, &game->win, 25, 25, 0xFFFF00, "Steps: ");
	mlx_string_put(&game->mlx, &game->win, 120, 25, 0xFFFF00, ft_itoa(game->steps)); //try changing x and y	
	if(game->finish)
			mlx_string_put(&game->mlx, &game->win, 150, 25, 0xFFFF00, "you won!");
}