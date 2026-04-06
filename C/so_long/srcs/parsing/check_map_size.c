/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 00:55:56 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/27 23:18:52 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool	check_map_size(char **map, t_map_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (ft_putstr_fd("Error\ninvalid size map\n", 2), false);
		i++;
	}
	if (i < 4 || len < 5)
		return (ft_putstr_fd("Error\ninvalid size map\n", 2), false);
	data->size_x = len;
	data->size_y = i;
	return (true);
}

static bool	is_valid_char(char c, int *exit, int *collec, int *spawn)
{
	if ((c == '1') || (c == '0'))
		return (true);
	else if (c == 'E')
		return (*exit += 1, true);
	else if (c == 'P')
		return (*spawn += 1, true);
	else if (c == 'C')
		return (*collec += 1, true);
	else
		return (false);
}

static bool	check_map_data(char **map)
{
	int	exit;
	int	collec;
	int	spawn;
	int	i;
	int	j;

	exit = 0;
	collec = 0;
	spawn = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j], &exit, &collec, &spawn))
				return (ft_putstr_fd("Error\nInvalid character in map\n", 2),
					false);
			j++;
		}
		i++;
	}
	if ((exit != 1) || (collec < 1) || (spawn != 1))
		return (ft_putstr_fd("Error\nInvalid number of 'C' or 'E' or 'P'\n", 2),
			false);
	return (true);
}

static bool	check_wall(char **map, t_map_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0 || x == 0 || y == (data->size_y - 1)
				|| x == (data->size_x - 1))
			{
				if (map[y][x] != '1')
					return (ft_putstr_fd("Error\ninvalid map border\n", 2),
						false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_map(char **map, t_map_data *data)
{
	if (!check_map_size(map, data))
		return (false);
	if (!check_map_data(map))
		return (false);
	if (!check_wall(map, data))
		return (false);
	return (true);
}