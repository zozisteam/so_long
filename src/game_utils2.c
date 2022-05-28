/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:33:42 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/28 12:25:00 by alalmazr         ###   ########.fr       */
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
	ft_printf("Error*** %s\n", msg);
	return (0);
}

int	close_win(t_game *game)
{
	ft_printf("you lose :(\n");
	free_map(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	end_game(t_game *game, int done)
{
	if (done)
	{
		game->steps++;
		ft_printf("Steps: %d\n", game->steps);
		ft_printf("you win :)\n");
	}
	else
		ft_printf("you lose :(\n");
	free_map(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
