/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:33:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/15 11:14:26 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}

//***under process
int	close_window(t_game *game)
{
	free_map(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

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
