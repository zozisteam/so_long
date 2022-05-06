#ifndef SO_LONG_H
# define SO_LONG_H

//defining paths
# define PATH_WALL "./files_img/wall.xpm"
# define PATH_EXIT "./files_img/exit.xpm"
# define PATH_PLAYER_DOWN "./files_img/player_down.xpm"
# define PATH_PLAYER_UP "./files_img/player_up.xpm"
# define PATH_PLAYER_RIGHT "./files_img/player_right.xpm"
# define PATH_PLAYER_LEFT "./files_img/player_left.xpm"
# define PATH_ITEM "./files_img/potion.xpm"
//defining keys
# define UP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ESC 0xff1b

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

//maybe no need
typedef struct s_img_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		line_size;
	int		endian;
}				t_img_data;

typedef struct s_player_direction
{
//
}				t_player_direction;

typedef struct s_img
{
	t_img_data	wall;
	t_img_data	emp;
	t_img_data	exit;
	t_img_data	pdown;
	t_img_data	pup;
	t_img_data	pleft;
	t_img_data	pright;
	t_img_data	item;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		finish;
	int		steps;
	int		init_game;
	int		side;
}				t_game;
//hooks
int		close_window(t_game *game);
int		key_event_handler(int keycode, t_game *game);
int		update(t_game *game);
//mlx
void	start_window(t_game *game);
t_img	put_image(void *mlx);
void	print_sprites(t_game *game, int line, int column);
//game
void	game_start_struct(t_game *game);
int		start_game(t_game *game, int argc, char **argv);
//game utils
void	free_map(char **map, t_map *map_struct);
int		error_msg(char *msg);
void	display_game_text(t_game *game);
void	end_game(t_game *game);
//map
char	**start_map(t_game *game, int argc, char **argv);
void	map_start_struct(t_map *map);
char	**read_map(char *path, t_map *map_struct);
void	print_map(t_game *game);
//map check
int		check_walls(char **map, t_map *map_struct);
int		check_args(int argc, char *map_file);
int		check_elements(t_map *map);
int		verify_elements(t_map *map);
//map utils
char	**map_malloc(char *path, t_map *map_struct);
void	player_starting_pos(t_map *map, int line, int col);
int		valid_map_element(char c);

#endif