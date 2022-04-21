/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:56:43 by apple             #+#    #+#             */
/*   Updated: 2022/04/21 06:32:29 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


t_img	put_image(void *mlx)
{
	t_img *img; //make sure this as a pointer is working or t_img img;

	img->wall.img = mlx_xpm_file_to_image(mlx, PATH_WALL, &img->wall.size.x, &img->wall.size.y);//decrease variable sizes in naming
	img->wall.bpp = mlx_get_data_addr(img->wall.img, &img->wall.bpp, &img->wall.line_size, &img->wall.endian);
	img->emp.img = mlx_xpm_file_to_image(mlx, PATH_EMPTY, &img->emp.size.x, &img->emp.size.y);
	img->emp.bpp = mlx_get_data_addr(img->emp.img, &img->emp.bpp,  &img->emp.line_size, &img->emp.endian);
	img->exit.img = mlx_xpm_file_to_image(mlx, PATH_EXIT, &img->exit.size.x, &img->exit.size.y);
	img->exit.bpp = mlx_get_data_addr(img->exit.img, &img->exit.bpp, &img->exit.line_size, &img->exit.endian);
	img->item.img = mlx_xpm_file_to_image(mlx, PATH_ITEM, &img->item.size.x, &img->item.size.y);
	img->item.bpp = mlx_get_data_addr(img->item.img, &img->item.bpp, &img->item.line_size, &img->item.endian);
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN, &img->player.down.size.x, &img->player.down.size.y);
	img->player.down.bpp = mlx_get_data_addr(img->player.down.img, &img->player.down.bpp, &img->player.down.line_size, &img->player.down.endian);
	img->player.left.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_LEFT, &img->player.left.size.x, &img->player.left.size.y);
	img->player.left.bpp = mlx_get_data_addr(img->player.left.img, &img->player.left.bpp, &img->player.left.line_size, &img->player.left.endian);
	img->player.up.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_UP, &img->player.up.size.x, &img->player.up.size.y);
	img->player.up.bpp = mlx_get_data_addr(img->player.up.img, &img->player.up.bpp, &img->player.up.line_size, &img->player.up.endian);
	img->player.down.img = mlx_xpm_file_to_image(mlx, PATH_PLAYER_DOWN, &img->player.down.size.x, &img->player.down.size.y);
	img->player.down.bpp = mlx_get_data_addr(img->player.down.img, &img->player.down.bpp, &img->player.down.line_size, &img->player.down.endian);
	return (*img);
}