/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:34:12 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/30 16:47:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

t_data	get_data(char *argv[])
{
	t_data	data;

	data.number_of_coders = atoi(argv[1]);
	data.time_to_burnout = atoi(argv[2]);
	data.time_to_compile = atoi(argv[3]);
	data.time_to_debug = atoi(argv[4]);
	data.time_to_refactor = atoi(argv[5]);
	data.compiles_required = atoi(argv[6]);
	data.dongle_cooldown = atoi(argv[7]);
	data.scheduler = argv[8];
	pthread_mutex_init(&data.message, NULL);
	return (data);
}
