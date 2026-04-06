/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:48:59 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/30 16:19:13 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"

void	run_startup(t_data *data)
{
	int	i;

	init_startup(data);
	i = -1;
	while (++i < data->number_of_coders)
		pthread_create(&data->coders[i]->thread, NULL, &work, data->coders[i]);
	pthread_create(&data->manager, NULL, &manager, data);
	pthread_mutex_lock(&data->death_mutex);
	data->finish = false;
	while (!data->finish)
		pthread_cond_wait(&data->finish_cond, &data->death_mutex);
	i = 0;
	pthread_mutex_unlock(&data->death_mutex);
	while (i < data->number_of_coders)
	{
		pthread_join(data->coders[i]->thread, NULL);
		pthread_mutex_destroy(&data->dongles[i]->dongle_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->death_mutex);
	pthread_cond_destroy(&data->finish_cond);
}

void	ft_free(t_data *data)
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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!args_checking(argc, argv))
		return (0);
	data = get_data(argv);
	if (data.number_of_coders >= 1)
	{
		run_startup(&data);
		ft_free(&data);
	}
	return (0);
}
