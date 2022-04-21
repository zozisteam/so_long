/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:42:03 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/21 06:42:18 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_sprites(t_game *game, int line, int column)
{
	int x;
	int y;

	x = column * TILES;
	y = line * TILES;
	if (&game->map.map[line][column] == 'P')
	{
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.down, x, y);
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.up, x, y);
		mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.left, x, y);			mlx_put_image_to_window(&game->mlx, &game->win, &game->img.player.right, x, y);
	}
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

void	print_map(t_game *game)
{
	int	x;
	int	y;
	char *steps;

	x = 0;
	while (x < &game->map.line)
	{
		y = 0;
		while (y < &game->map.column)
		{
			print_sprites(x, y, game);
			y++;
		}
		x++;
		steps = ft_itoa(game->steps);
		mlx_string_put(&game->mlx, &game->win, 25, 25, 0xFFFF00, "Steps: ");
		mlx_string_put(&game->mlx, &game->win, 120, 25, 0xFFFF00, steps); //try changing x and y
		free(steps);
		if(game->end_game)
			mlx_string_put(&game->mlx, &game->win, 150, 25, 0xFFFF00, "you won!");
	}
}
