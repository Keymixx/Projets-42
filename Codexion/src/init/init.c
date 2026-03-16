/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:41:18 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/16 18:40:34 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void dongle_init(t_data *data)
{
	int				i;
	int 			nb_coders;
	t_dongles 		**dongles;
	
	nb_coders = data->number_of_coders;
	dongles = malloc(sizeof(t_dongles *) * nb_coders);
	i = 0;
	while (i < nb_coders)
	{
		dongles[i] = malloc(sizeof(t_dongles));
		dongles[i]->queue[1] = -1;
		dongles[i]->queue[2] = -1;
		pthread_mutex_init(&dongles[i++]->dongle_mutex, NULL);
	}
	data->coders[0]->l_dongle = dongles[nb_coders - 1];
	data->coders[0]->r_dongle = dongles[0];
	i = 1;
	while(i < nb_coders)
	{
		data->coders[i]->l_dongle = dongles[i - 1];
		data->coders[i]->r_dongle = dongles[i];
		i++;
	}
	data->dongles = dongles;
}

void monitoring_init(t_data *data)
{
	t_monitoring manager;

	manager.dongle_cooldown = data->dongle_cooldown;
	manager.compiles_required = data->compiles_required;
	manager.scheduler = data->scheduler;
	pthread_mutex_init(&manager.message, NULL);
	pthread_cond_init(&manager.death, NULL);

	data->manager = &manager;
}	

void coders_init(t_data *data)
{
	int	i;
	t_coder **all_coders;

	i = 0;
	all_coders = malloc(sizeof(t_coder *) * data->number_of_coders + 1);
	while(i < data->number_of_coders)
	{
		all_coders[i] = malloc(sizeof(t_coder));
		all_coders[i]->id = i + 1;
		all_coders[i]->time_to_burnout = data->time_to_burnout;
		all_coders[i]->time_to_compile = data->time_to_compile;
		all_coders[i]->time_to_debug = data->time_to_debug;
		all_coders[i]->time_to_refactor = data->time_to_refactor;
		all_coders[i]->message = &data->message;
		i++;
	}
	all_coders[i] = NULL;
	data->coders = all_coders;
}
