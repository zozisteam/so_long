#ifndef SO_LONG_H
# define SO_LONG_H

//defining paths
# define PATH_WALL "path"
# define PATH_EMPTY ""
# define PATH_EXIT ""
# define PATH_PLAYER_DOWN ""
# define PATH_PLAYER_UP "./images/WHATEVER.xpm"
# define PATH_PLAYER_RIGHT ""
# define PATH_PLAYER_LEFT ""
# define PATH_ITEM ""
//defining keys
# define UP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ESC 0xff1b

//my xml images are 100*100
# define TILES 100

# include "./mlx/mlx.h"
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

typedef struct s_map_check
{
	int	player;
	int	exit;
	int	collect;
}				t_map_check;

typedef struct s_map
{
	t_pos		player;
	int			valid;
	int			end_col;
	int			column;
	int			line;
	t_map_check	check;
	char		**map;
}				t_map;

typedef struct s_img_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	//int		bpp;
	int		line_size;
	int		endian;
}				t_img_data;

typedef struct s_player_direction
{
	t_img_data	down;
	t_img_data	up;
	t_img_data	left;
	t_img_data	right;
}				t_player_direction;

typedef struct s_img
{
	t_img_data			wall;
	t_img_data			emp;
	t_img_data			exit;
	t_player_direction	player;
	t_img_data			item;
	t_img_data			enemy;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		finish; //end_game
	int		steps;
	int		init_game;
	int		side;
}				t_game;


//mlx
t_img	put_image(void *mlx);
void	start_window(t_game *game);
void	print_sprites(t_game *game, int line, int column);

//game
int		start_game(t_game *game, int argc, char **argv);
void	game_start_struct(t_game *game);
//game utils
void	free_map(char **map, t_map *map_struct);
int		error_msg(char *msg);
void	display_game_text(t_game *game);
void	delete_player(t_game *game);
//map
char	**start_map(t_game *game, int argc, char **argv);
void 	map_start_struct(t_map *map);
char	**read_map(char *path, t_map *map_struct);
void	print_map(t_game *game);
//map check
int		check_walls(char **map, t_map *map_struct);
int		check_args(int argc, char *map_file);
//map utils
char	**map_malloc(char *path, t_map *map_struct);
int		map_player(t_map *map, int line, int col);
int		valid_map_char(char c)

//hooks
int		close_window(t_game *game);
int		key_event_handler(int keycode, t_game *game);

#endif