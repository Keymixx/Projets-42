/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:33:25 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/25 22:22:38 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define P_FLOOR "textures/floor.xpm"
#define P_EXIT "textures/exit.xpm"
#define P_UNBREAK "textures/unbreak.xpm"
#define P_UPWALL "textures/up_wall.xpm"
#define P_LT_WALL "textures/left_wall.xpm"

#define UNBEAK_WALL '3'
#define WALL '1'
#define ROCK '2'
#define EMPTY '0'
#define COLLEC 'C'
#define EXIT 'E'
#define SPAWN 'P'

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

typedef struct	s_map_size {
	int			x;
	int			y;
}				t_map_size;


typedef struct	s_cell_data{

	int			wall;
	bool		empty;
	bool		collec;
	bool		exit; 
	bool		spawn;                 
}				t_cell_data;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

bool check_map(char **map, t_map_size *map_size);
bool check(char **tab_map, t_map_size *map_size);
char **create_tab_map(char *filname);
bool check_args(int argc, char *argv[]);

#endif