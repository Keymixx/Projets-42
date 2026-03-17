/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:48:59 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/17 16:15:49 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"

bool all_alive(t_coder **coders, int nb_coders)
{
	int	i;
	
	i = 0;
	while(i < nb_coders)
	{
		if(!coders[i]->alive)
			return false;
		i++;
	}
	return true;
}

void run_startup(t_data *data)
{
	int	i;

	pthread_cond_init(&data->death_cond, NULL);
	coders_init(data);
	dongle_init(data);
	
	printf("\n");
	
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_create(&data->coders[i]->thread, NULL, &work, data->coders[i]);
		i++;
	}
	pthread_mutex_lock(&data->death_mutex);
	while (all_alive(data->coders, data->number_of_coders))
		pthread_cond_wait(&data->death_cond, &data->death_mutex);
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_mutex_destroy(&data->dongles[i]->dongle_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->death_mutex);
	pthread_cond_destroy(&data->death_cond);
}

int	main(int argc, char	*argv[])
{
	t_data			data;
	
	if (!args_checking(argc, argv))
		return (0);
	data = get_data(argv);
	if (data.number_of_coders > 1)
		run_startup(&data);
	
	return(0);
}
