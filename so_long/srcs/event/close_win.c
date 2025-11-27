/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:47:32 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/27 21:48:14 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int close_win(int keycode, t_map_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win_mlx);
		exit(0);
	}
	return (0);
}
