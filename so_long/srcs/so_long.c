/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:32:47 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/26 00:12:39 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void *choose_sprite(char c, t_map_size map_size, void *mlx)
{
	void *cell;
	int		width;
	int		height;

	(void)map_size;
	if (c == EMPTY || c == COLLEC || c == SPAWN)
		cell = mlx_xpm_file_to_image(mlx, P_FLOOR, &width, &height);
	if (c == WALL)
		cell = mlx_xpm_file_to_image(mlx, P_UPWALL, &width, &height);
	if (c == EXIT)
		cell = mlx_xpm_file_to_image(mlx, P_EXIT, &width, &height);
	return (cell);	
}

void create_map(char **tab_map, t_map_size map_size, void *mlx, void *mlx_win)
{
	int	i;
	int j;
	void	*cell;

	i = 0;
	while (tab_map[i])
	{
		j = 0;
		while (tab_map[i][j])
		{
			cell = choose_sprite(tab_map[i][j], map_size, mlx);
			mlx_put_image_to_window(mlx, mlx_win, cell, (j * 64), (i * 64));
			free(cell);
			printf("i = %d et j = %d\n", i*64, j*64);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	void	*mlx_win;
	char 	**tab_map;
	t_map_size map_size;
	void	*mlx;
	
	if (!check_args(argc, argv))
		exit(EXIT_FAILURE);
	tab_map = create_tab_map(argv[1]);
	if(!check(tab_map, &map_size))
		exit(EXIT_FAILURE);
	map_size.x = map_size.x * 64;
	map_size.y = map_size.y * 64;
	int i = 0;
	while (tab_map[i])
		printf("%s\n",tab_map[i++]);
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_size.x, map_size.y, "CARL");
	create_map(tab_map, map_size, mlx, mlx_win);
	mlx_loop(mlx);
	ft_free(tab_map);
	free(mlx);
	free(mlx_win);
}
