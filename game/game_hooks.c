/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:17:41 by apple             #+#    #+#             */
/*   Updated: 2022/04/21 18:42:54 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* Free the allocated memory of the map and close the window */
int	close_window(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

/* Handle the events of the game and call a auxiliary function */
/* to make an action */
int	action(int key, t_game *game)
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
	if (!game->end_game)
		move_player(game, line, col, key);

	return (1);
}

void	move_player(t_game *game, int line, int col, int key) //*******
{
	int	y;
	int	x;
	int	valid;

	y = game->map.player.y;
	x = game->map.player.x;
	valid = verify_move(game, line, col, key); //create function to verify move**********
	//check_side(update_direction) and update where player is facing depending on key pressed
	update_direction(key, game);
	//if game->end =1 then call function to kill player
	if (valid > 0)
	{
		if (game->map.map[line][col] == 'C')
			game->map.check.collect--; //if we move to collectible we decrement
		game->map.map[x][y] = '0'; //old pos will be empty
		game->map.map[line][col] = 'P'; //new pos will be player
		game->map.player.x = line; //update player x and y
		game->map.player.y = col;
		game->steps++; //increment steps
	}
}

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
	game->side = key;
}

/* Draws the map and clear the window when the counter reset is 30 */
int	update(t_game *game)
{
	print_map(game);
	return (0);
}