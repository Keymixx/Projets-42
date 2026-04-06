/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:32:33 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/30 16:47:51 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

bool	all_alive(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_coders)
	{
		if (data->coders[i]->last_compile
			+ data->time_to_burnout < get_current_time())
		{
			pthread_mutex_lock(&data->death_mutex);
			if (data->coders[i]->all_alive != 0)
				printf("%lld %d burned out\n", (get_current_time()
						- *data->coders[i]->time), data->coders[i]->id);
			*data->coders[i]->all_alive = 0;
			i = 0;
			while (i < data->number_of_coders)
				pthread_cond_broadcast(&data->dongles[i++]->dongle_cond);
			pthread_cond_broadcast(&data->finish_cond);
			pthread_mutex_unlock(&data->death_mutex);
			return (false);
		}
		i++;
	}
	return (true);
}

void	*manager(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(1000);
	while (all_alive(data) && !project_finish(data))
	{
		usleep(500);
	}
	data->all_alive = false;
	data->finish = true;
	pthread_cond_broadcast(&data->finish_cond);
	return (NULL);
}
