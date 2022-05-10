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

typedef struct s_map
{
	t_pos		player;
	int			valid;
	int			column;
	int			line;
	char		**map;
	int			player_count;
	int			exit;
	int			collect;
}				t_map;

//maybe no need
typedef struct s_img
{
	void	*img;
	t_pos	pos;
	t_pos	size;
}				t_img;

typedef struct s_all_imgs
{
	t_img	wall;
//	t_img	emp;
	t_img	exit;
	t_img	pdown;
	t_img	pup;
	t_img	pleft;
	t_img	pright;
	t_img	item;
}				t_all_imgs;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_all_imgs	img;
	int			finish;
	int			steps;
	int			init_game;
	int			side;
}				t_game;
//hooks
int			close_window(t_game *game);
int			key_event_handler(int keycode, t_game *game);
int			update(t_game *game);
//mlx
void		start_window(t_game *game);
t_all_imgs	put_image(void *mlx);
void		print_sprites(t_game *game, int line, int column);
//game
void		game_start_struct(t_game *game);
int			game_start(t_game *game, int argc, char **argv);
//game utils
void		free_map(char **map, t_map *map_struct);
int			error_msg(char *msg, t_map *map_struct);
void		display_game_text(t_game *game);
void		end_game(t_game *game);
//map
char		**start_map(t_game *game, int argc, char **argv);
void		map_start_struct(t_map *map);
char		**read_map(char *path, t_map *map_struct);
void		print_map(t_game *game);
//map check
int			check_walls(char **map, t_map *map_struct);
int			check_args(int argc, char *map_file);
int			check_elements(t_map *map);
int			verify_elements(t_map *map);
int			check_extension(char *map_file, char *ext);
//map utils
char		**map_malloc(char **map, char *path, t_map *map_struct);
void		player_starting_pos(t_map *map, int line, int col);
int			valid_map_element(char c);

#endif