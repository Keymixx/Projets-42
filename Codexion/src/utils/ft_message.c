/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:47:46 by carl              #+#    #+#             */
/*   Updated: 2026/03/19 17:48:09 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void ft_message(char *str, t_coder coder)
{       
    size_t current_time;
    
    current_time = (long)get_current_time() - (long)*coder.time;
	pthread_mutex_lock(coder.death_mutex);
    if((get_current_time() - coder.last_compile) > coder.time_to_burnout && *coder.all_alive != 0)
	{
		*coder.all_alive = 0;
		printf("%d burned out\n", coder.id);
        printf("time - last compile = %ld and time to_burn = %ld\n", get_current_time() - coder.last_compile, coder.time_to_burnout);
		pthread_cond_broadcast(coder.death_cond);
	}
    if(*coder.all_alive != 0)
    {
        printf("%ld %d %s\n",current_time ,coder.id, str);
    }
    else
    {
        pthread_mutex_unlock(coder.death_mutex);
        return;
    }
    pthread_mutex_unlock(coder.death_mutex);
}