/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:01:16 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/27 23:19:10 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


static bool check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (i < 0)
		return (ft_putstr_fd("Error\ninvalid map\n", 2), false);
	if (strncmp(&str[i], ".ber", 4) == 0)
		return (true);
	else
		return(ft_putstr_fd("Error\ninvalid map : (.ber)\n", 2), false);
	
}
bool check_args(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_putstr_fd("Error\ninvalid number of argument\n", 2), false);
	if (!check_ber(argv[1]))
		return (false);
	return (true);
}

bool check(char **tab_map, t_map_data *data)
{
	if (!tab_map)
		return (false);
	if (!check_map(tab_map, data))
		return (false);
	return (true);
}	