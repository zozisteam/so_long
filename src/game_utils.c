/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:33:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/07 20:29:14 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, t_map *map_struct)
{
	int	i;

	i = 0;
	while (i <= map_struct->line)
		free(map[i++]);
	free(map);
}

//***under process
int	close_window(t_game *game)
{
	free_map(game->map.map, &game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}s

int	error_msg(char *msg, t_map *map_struct)
{
	if (map_struct)
		map_struct->valid = 0;
	ft_printf("Error\n*%s*\n", msg);
	return (0);
}

//***under process
void	end_game(t_game *game)
{
	if (game->finish)
		ft_printf("you win :)\n");
	else
		ft_printf("you lose :(\n");
	close_window(game);
}
