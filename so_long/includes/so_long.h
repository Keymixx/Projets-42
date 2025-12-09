/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:33:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/12/01 13:28:10 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
//---------PATH_SPRITE------------
#define P_FLOOR "textures/floor.xpm"
#define P_EXIT "textures/exit.xpm"
#define P_UNBREAK "textures/unbreak.xpm"
#define P_UPWALL "textures/up_wall.xpm"
#define P_LT_WALL "textures/left_wall.xpm"
#define P_COLLEC "textures/collec.xpm"
#define P_PLAYER "textures/player.xpm"
//--------CHARACTER_MAP------------
#define UNBEAK_WALL '3'
#define WALL '1'
#define ROCK '2'
#define EMPTY '0'
#define COLLEC 'C'
#define EXIT 'E'
#define SPAWN 'P'
//--------KEYCODE------------
#define ESC 65307
#define LT_ARROW 65361
#define UP_ARROW 65362
#define RT_ARROW 65363
#define DN_ARROW 65364
#define Z 90
#define Q 81
#define S 83
#define D 68

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_img_data
{
	void *img_floor;
	void *img_player;
	void *img_collec;
	void *img_wall;
	void *img_exit;
} t_img_data;

typedef struct s_player_info
{
	int pos_x;
	int pos_y;
	void *img;
} t_player_info;

typedef struct s_map_data
{
	char **tab_map;
	int size_x;
	int size_y;
	t_img_data *img;
	t_player_info player;
	void *mlx;
	void *win_mlx;

} t_map_data;

typedef struct s_cell_data
{
	int wall;
	bool empty;
	bool collec;
	bool exit;
	bool spawn;
} t_cell_data;

bool check_map(char **map, t_map_data *data);
bool check(char **tab_map, t_map_data *data);
char **create_tab_map(char *filname);
bool check_args(int argc, char *argv[]);
int close_win(int keycode, t_map_data *data);

#endif