/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 01:10:51 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/27 23:54:31 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static bool double_n(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return(true);
		i++;
	}
	return (false);
}

char **create_tab_map(char *filname)
{
	int	i;
	int fd;
	char *buf;
	char *map;
	char **tab_map;

	map = NULL;
	i = 0;
	fd = open(filname, O_RDONLY);
	if (!fd)
		return (ft_putstr_fd("Error\ncannot open the file\n", 2), free(map), NULL);
	buf = get_next_line(fd);
	while (buf)
	{
		map = ft_strjoin_gnl(map,buf);
		free(buf);
		buf = get_next_line(fd);
	}
	free(buf);
	printf("DEBUG: map = %p\n", map);  // Ajoute ça
	if(double_n(map))
		return (ft_putstr_fd("Error\ninvalid map\n", 2), NULL);
	tab_map = ft_split(map,'\n');
	free (map);
	return (tab_map);
}
