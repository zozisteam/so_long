/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:46:13 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/07 20:00:49 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// //put this in images
// void	update_direction(int key, t_game *game)
// {
// 	if (key == UP)
// 		game->side = UP;
// 	if (key == DOWN)
// 		game->side = DOWN;
// 	if (key == LEFT)
// 		game->side = LEFT;
// 	if (key == RIGHT)
// 		game->side = RIGHT;
// 	//or
// 	//game->side = key;
// }

int	can_move(t_game *game, int line, int col, int key)
{
	if (key != UP && key != DOWN && key != LEFT && key != RIGHT)
		return (0);
	if (game->map.map[line][col] == '1')
		return (0);
	if (game->map.map[line][col] == 'E' && game->map.collect == 0)
		game->finish = 1;
	if (game->finish)
		return (0);
	if (game->map.map[line][col] == 'E') //collectibles not 0
		return (0);
	else
		return (1);
}

void	move_player(t_game *game, int line, int col, int key)
{
	int	y;
	int	x;
	//*******
	y = game->map.player.y;
	x = game->map.player.x;
	//update where player is facing depending on key pressed (maybe needs change bcz redund)
	game->side = key;
	if (can_move(game, line, col, key) && !game->finish)
	{
		if (game->map.map[line][col] == 'C')
			game->map.collect--; //if we move to collectible we decrement
		game->map.map[game->map.player.y][game->map.player.x] = '0'; //old pos will be empty
		game->map.map[line][col] = 'P'; //new pos will be player
		game->map.player.y = line; //update player x and y
		game->map.player.x = col;
		game->steps++; //increment steps
		ft_printf("Steps: %d\n", game->steps);
		print_map(game);
	}
}

int	key_event_handler(int key, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y; //we get the values of x and y and update them depending on what key was pressed
	col = game->map.player.x;
	if (key == ESC || game->finish)
		close_window(game);
	if (key == UP)
		line--;
	if (key == DOWN)
		line++;
	if (key == RIGHT)
		col++;
	if (key == LEFT)
		col--;
	if (!game->finish)
		move_player(game, line, col, key);
	return (1);
}

int	update(t_game *game)
{
	if (!game->finish)
		print_map(game);
	return (0);
}
