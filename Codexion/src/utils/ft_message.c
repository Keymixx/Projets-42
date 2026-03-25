/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:47:46 by carl              #+#    #+#             */
/*   Updated: 2026/03/25 15:41:32 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void ft_message(char *str, t_coder *coder)
{       
    long long current_time;
    
    current_time = get_current_time() - *coder->time;
	pthread_mutex_lock(coder->death_mutex);
    if((get_current_time() - coder->last_compile) > coder->time_to_burnout && *coder->all_alive != 0)
	{
		*coder->all_alive = 0;
		printf("%lld %d burned out\n",current_time, coder->id);
	}
    if(*coder->all_alive != 0)
        printf("%lld %d %s\n",current_time ,coder->id, str);
    pthread_mutex_unlock(coder->death_mutex);
}