/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:33:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/26 00:15:55 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free((void *)map[i++]);
	free(map[i]);
	free(map);
}

int	error_msg(char *msg)
{
	ft_printf("Error\n*%s*\n", msg);
	return (0);
}

int	end_game(t_game *game, int done)
{
	if (done)
		ft_printf("you win :)\n");
	else
		ft_printf("you lose :(\n");
	free_map(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
