/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:44:43 by carl              #+#    #+#             */
/*   Updated: 2026/03/27 16:57:37 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long long milliseconds, t_coder *coder)
{
	long long	start;
	start = get_current_time();
	while ((get_current_time() - start) < milliseconds && *coder->all_alive != 0)
	{
		usleep(500);
		if((get_current_time() - coder->last_compile) > coder->time_to_burnout && *coder->all_alive != 0)
		{
			pthread_mutex_lock(coder->death_mutex);
			if (*coder->all_alive != 0)
				printf("%lld %d burned out\n",get_current_time() - *coder->time, coder->id);
			*coder->all_alive = 0;
			pthread_cond_broadcast(coder->finish_cond);
			pthread_mutex_unlock(coder->death_mutex);
			return(0);
		}
		usleep(500);
	}
	return (0);
}
