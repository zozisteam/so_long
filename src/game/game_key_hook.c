/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:46:13 by alalmazr          #+#    #+#             */
/*   Updated: 2022/04/26 07:51:03 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//put this in images
void	update_direction(int key, t_game *game)
{
	if (key == UP)
		game->side = UP;
	if (key == DOWN)
		game->side = DOWN;
	if (key == LEFT)
		game->side = LEFT;
	if (key == RIGHT)
		game->side = RIGHT;
	//or
	//game->side = key;
}

int can_move(t_game *game, int line, int col, int key)
{
	if (key != UP && key != DOWN && key != LEFT && key != RIGHT)
		return (0);
	if (game->map.map[line][col] == '1')
		return (0);
	if (game->map.map[line][col] == 'E' && game->map.check.collect == 0)
		game->finish = 1;
	if (game->finish)
		return (0);
	if (game->map.map[line][col] == 'E') //collectibles not 0
		return (0);
	if (game->map.map[line][col] == 'V')
	{
		delete_player(game);
		return (0);
	}
	else
		return (1);
}

void	move_player(t_game *game, int line, int col, int key) //*******
{
	int	y;
	int	x;
	int	valid;

	y = game->map.player.y;
	x = game->map.player.x;
	//check_side(update_direction) and update where player is facing depending on key pressed
	update_direction(key, game);
	//if game->end =1 then call function to kill player
	if (can_move(game, line, col, key)) //maybe make this diff function move(valid, ...)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.collect--; //if we move to collectible we decrement
		game->map.map[y][x] = '0'; //old pos will be empty
		game->map.map[line][col] = 'P'; //new pos will be player
		game->map.player.y = line; //update player x and y
		game->map.player.x = col;
		game->steps++; //increment steps
	}
}

/* Handle the events of the game and call a auxiliary function */
/* to make an key_event_handler */
int	key_event_handler(int key, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y; //we get the values of x and y and update them depending on what key was pressed
	col = game->map.player.x;
	if (key == ESC)
		close_win(game);
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
