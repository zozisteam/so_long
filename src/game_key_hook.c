/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:46:13 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/25 16:10:59 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check the coordinates (line,col) if it is a valid
//position for the player to go to (eg. not a wall, not
//the exit if collect is not 0.. etc)
//also check that the key pressed is a valid key
int	can_move(t_game *game, int line, int col, int key)
{
	if (key != UP && key != DOWN && key != LEFT && key != RIGHT)
		return (0);
	if (game->map.map[line][col] == '1')
		return (0);
	if (game->map.map[line][col] == 'E' && game->map.collect == 0)
	{
		game->finish = 1;
		end_game(game);
	}
	if (game->finish)
		return (0);
	if (game->map.map[line][col] == 'E')
		return (0);
	else
		return (1);
}

//move player
//update where player should be facing depending key direction
//if next move is valid and game is not finished
//if we're going on a item tile we decrement items count
//then we make the old player tile empty and change the new pos
//into a player tile. after than increment steps bcz we just moved and print
void	move_player(t_game *game, int line, int col, int key)
{
	int	y;
	int	x;

	y = game->map.player.y;
	x = game->map.player.x;
	game->side = key;
	if (can_move(game, line, col, key) && !game->finish)
	{
		if (game->map.map[line][col] == 'C')
			game->map.collect--;
		game->map.map[game->map.player.y][game->map.player.x] = '0';
		game->map.map[line][col] = 'P';
		game->map.player.y = line;
		game->map.player.x = col;
		game->steps++;
		ft_printf("Steps: %d\n", game->steps);
		print_map(game);
	}
}

//this function handles key pressing
//we get the pos (x,y) and store them
//in (line,col) and depending on what key was pressed
//we get the new (line,col) that we want to move the
//player to then call move_player with new pos
//if escape key pressed or game is finished we close window
int	key_event_handler(int key, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (key == ESC || game->finish)
		end_game(game);
	if (key == UP)
		line--;
	if (key == DOWN)
		line++;
	if (key == RIGHT)
		col++;
	if (key == LEFT)
		col--;
	move_player(game, line, col, key);
	return (1);
}
