/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:32:33 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/27 15:43:25 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"


bool all_alive(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->number_of_coders)
	{
		if(data->coders[i]->last_compile + data->time_to_burnout > get_current_time())
		{
			return(false);
		}
		i++;
	}
	return(true);
}

void *manager(void *arg)
{
	t_data *data;
	
	data = (t_data *)arg;
	usleep(500);
	while (all_alive(data))
	{
		// printf("a = %lld ; b = %lld\n", data->coders[i]->last_compile + data->time_to_burnout, get_current_time());
		usleep(500);
		// printf("%d  %lld\n", all_alive(data), get_current_time());
	}
	data->finish = true;
	pthread_cond_broadcast(&data->finish_cond);
	return NULL;
}