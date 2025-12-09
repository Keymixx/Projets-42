/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:32:47 by caaubert          #+#    #+#             */
/*   Updated: 2025/12/01 13:38:57 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*choose_sprite(char c, t_img_data *img)
{
	void	*cell;
	
	cell = img->img_floor;
	if (c == WALL)
		cell = img->img_wall;
	if (c == EXIT)
		cell = img->img_exit;
	if (c == COLLEC)
		cell = img->img_collec;
	if (c == SPAWN)
		cell = img->img_player;
	return (cell);
}

void	create_map(char **tab_map, t_map_data *data, t_img_data *img)
{
	int		i;
	int		j;
	void	*cell;

	i = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			cell = choose_sprite(tab_map[i][j], img);
			mlx_put_image_to_window(data->mlx, data->win_mlx, cell, (j * 64), (i* 64));
			if (tab_map[i][j] == SPAWN)
			{
				data->player.pos_x = j * 64;
				data->player.pos_y = i * 64;
			}
			j++;
		}
		i++;
	}
}
bool is_valid_move(t_map_data *data, int new_pose_x, int new_pose_y)
{
	
}

int	move_player(int keycode, t_map_data *data)
{
	int new_pose_x;
	int new_pose_y;

	new_pose_x = data->player.pos_x;
	new_pose_y = data->player.pos_y;
	if (keycode == LT_ARROW && is_valid_move(data, new_pose_x + 64, new_pose_y))
		data->player.pos_x -= 64;
	if (keycode == RT_ARROW)
		data->player.pos_x += 64;
	if (keycode == UP_ARROW)
		data->player.pos_y -= 64;
	if (keycode == DN_ARROW)
		data->player.pos_y += 64;
	mlx_put_image_to_window(data->mlx, data->win_mlx, data->player.img, data->player.pos_x , data->player.pos_y);
	return (0);
}

void	init_img(t_img_data *img, t_map_data *data)
{
	int	width;
	int	height;
	
	img->img_floor = mlx_xpm_file_to_image(data->mlx, P_FLOOR, &width, &height);
	img->img_exit = mlx_xpm_file_to_image(data->mlx, P_EXIT, &width, &height);
	img->img_collec = mlx_xpm_file_to_image(data->mlx, P_COLLEC, &width, &height);
	img->img_player = mlx_xpm_file_to_image(data->mlx, P_PLAYER, &width, &height);
	data->player.img = img->img_player;
	img->img_wall = mlx_xpm_file_to_image(data->mlx, P_UPWALL, &width, &height);
}

int	main(int argc, char *argv[])
{
	t_map_data	data;
	t_img_data	img;

	if (!check_args(argc, argv))
		exit(EXIT_FAILURE);
	data.tab_map = create_tab_map(argv[1]);
	if (!check(data.tab_map, &data))
	{
		ft_free(data.tab_map);
		exit(EXIT_FAILURE);
	}
		
	
	data.size_x = data.size_x * 64;
	data.size_y = data.size_y * 64;
	data.mlx = mlx_init();
	data.win_mlx = mlx_new_window(data.mlx, data.size_x, data.size_y, "CARL");
	init_img(&img, &data);	
	// mlx_key_hook(data.win_mlx, &close_win, &data);
	create_map(data.tab_map, &data, &img);
	mlx_key_hook(data.win_mlx, &move_player, &data);
	mlx_loop(data.mlx);
	ft_free(data.tab_map);
}
