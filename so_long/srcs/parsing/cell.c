/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:51:01 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/25 18:51:45 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_cell_data set_cell(char c)
{
	t_cell_data cell;

	cell.collec = false;
	cell.exit = false;
	cell.empty = false;
	cell.spawn = false;
	cell.wall = 0;
	if (c == '0')
		return (cell.empty = true, cell);
	else if (c == '1')
		return (cell.wall = 1, cell);
	else if (c == 'C')
		return (cell.collec = true, cell);
	else if (c == 'P')
		return (cell.spawn = true, cell);
	else 
		return (cell.exit = true, cell);
}

t_cell_data **create_map(char **tab_map, t_map_size map_size)
{
	t_cell_data **map;
	int			i;
	int			j;

	i = 0;
	map = malloc(sizeof(t_cell_data *) * (map_size.y + 1));
	while (tab_map[i])
	{
		j = 0;
		map[i] = malloc(sizeof(t_cell_data) * (map_size.x + 1));
		while (tab_map[i][j])
		{
			map[i][j] = set_cell(tab_map[i][j]);
			j++;
		}
		i++;
	}
	return (map);
}

void print_cell(t_cell_data map)
{
	if (map.empty == true)
		printf ("empty");
	if (map.wall == true)
		printf ("wall");
	if (map.spawn == true)
		printf ("spawn");
	if (map.collec == true)
		printf ("collec");
	if (map.exit == true)
		printf ("exit");
}
