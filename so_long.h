/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalmazr <alalmazr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:49:08 by alalmazr          #+#    #+#             */
/*   Updated: 2022/05/29 14:01:29 by alalmazr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//defining paths
# define PATH_WALL "./files_img/wall.xpm"
# define PATH_EXIT "./files_img/exit.xpm"
# define PATH_PLAYER_DOWN "./files_img/player_down.xpm"
# define PATH_PLAYER_UP "./files_img/player_up.xpm"
# define PATH_PLAYER_RIGHT "./files_img/player_right.xpm"
# define PATH_PLAYER_LEFT "./files_img/player_left.xpm"
# define PATH_ITEM "./files_img/item.xpm"
# define PATH_EMPTY "./files_img/empty.xpm"
//defining keys
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

//my xpm images are 50*50
# define TILES 50

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_position
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_map
{
	t_pos		player;
	int			column;
	int			line;
	char		**map;
	int			player_count;
	int			exit;
	int			collect;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	int			steps;
	int			side;
}				t_game;
//hooks
int			key_event_handler(int keycode, t_game *game);
int			close_win(t_game *game);
//mlx
void		start_window(t_game *game);
void		put_image(t_game *game, char *path, int line, int col);
void		put_tile(t_game *game, int line, int column);
//game
void		game_start_struct(t_game *game);
int			game_start(t_game *game, char **argv);
//map
void		map_start_struct(t_map *map);
char		**start_map(t_game *game, int argc, char **argv);
int			read_map(char *path, t_map *map_struct);
void		print_map(t_game *game);
//map check
int			check_walls(t_map *map_struct);
int			check_args(int argc, char *map_file);
int			check_extension(char *map_file, char *ext);
int			count_map_elements(t_map *map);
int			verify_map_elements(t_map *map);
//utils
void		free_map(char **map);
int			map_count_lines(t_map *map_struct);
int			map_count_columns(t_map *map_struct);
int			error_msg(char *msg);
int			end_game(t_game *game, int done);
void		player_starting_pos(t_map *map, int line, int col);
void		put_player_tile(t_game *game, int line, int col);
int			is_element_ok(char c);

#endif