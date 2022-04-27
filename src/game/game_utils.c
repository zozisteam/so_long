/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:33:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/27 07:00:33 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map(char **map, t_map *map_struct)
{
	int i;

	i = 0;
	while (i <= map_struct->line)
		free(map[i++]);
	free(map);
}

//***under process
int	close_window(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
	//mlx_destroy_window(game->mlx, game->win);
}

int error_msg(char *msg)
{
	ft_printf("Error\n*%s*\n", msg);
	return (-1);
}

//***under process
void	delete_player(t_game *game)
{
	game->map.map[game->map.player.y][game->map.player.x] = '0';
	//game->side = DOWN;
	print_map(game);
}