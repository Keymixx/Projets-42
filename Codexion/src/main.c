/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:48:59 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/19 17:45:19 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"


void run_startup(t_data *data)
{
	int	i;

	pthread_cond_init(&data->death_cond, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	data->all_alive = 1;
	coders_init(data);
	dongle_init(data);
	data->time = get_current_time();
	printf("\n");
	
	i = 0;
	while (i < data->number_of_coders)
	{
		pthread_create(&data->coders[i]->thread, NULL, &work, data->coders[i]);
		i++;
	}
	pthread_mutex_lock(&data->death_mutex);
	while (data->all_alive) // ou ton état
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

void ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		free(data->coders[i]);
		free(data->dongles[i]);
		i++;
	}
	free(data->coders);
	free(data->dongles);
}

int	main(int argc, char	*argv[])
{
	t_data			data;
	
	if (!args_checking(argc, argv))
		return (0);
	data = get_data(argv);
	if (data.number_of_coders > 1)
		run_startup(&data);
	ft_free(&data);
	printf("caca\n");
	return(0);
}
