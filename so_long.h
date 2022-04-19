#ifndef SO_LONG_H
# define SO_LONG_H
//defining keys
# define TOP 0x77
# define DOWN 0x73
# define LEFT 0x61
# define RIGHT 0x64
# define ESC 0xff1b
# define RESET 0x72

# define TILES 50

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
	t_pos		player_bup;
	int			valid;
	int			end_col;
	int			column;
	int			line;
	t_map_check	check;
	int			item_bup;
	char		**map;
	char		**backup_map;
}				t_map;

typedef struct s_data
{
	void	*img;
	char	*pixel;
	t_pos	pos;
	t_pos	size;
	int		bpp;
	int		line_size;
	int		endian;
}				t_data;

typedef struct s_side
{
	t_data	down;
	t_data	top;
	t_data	left;
	t_data	right;
}				t_side;

typedef struct s_img
{
	t_data	wall;
	t_data	emp;
	t_data	exit;
	t_side	player;
	t_data	item;
	t_data	enemy;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		end_game;
	int		steps;
	int		init_game;
	double	reset;
	int		side;
}				t_game;

//utils

//map functions + printing

//initializing functions

//games

//errors

#endif