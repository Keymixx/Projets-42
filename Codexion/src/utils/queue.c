/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:55 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/25 17:10:10 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void push(t_dongles *dongle, t_coder *coder);
void pop(t_dongles *dongle, t_coder *coder);
t_coder *turn(char *str, t_dongles *dongle);

void lock_mutex(t_dongles *dongle, t_coder *coder)
{
	pthread_mutex_lock(&dongle->dongle_mutex);
	if(!dongle->is_taken && dongle->dongle_avaible <= get_current_time())
	{
		dongle->is_taken = true;
		pthread_mutex_unlock(&dongle->dongle_mutex);
		return;		
	}
	push(dongle, coder);
	while(turn(dongle->scheduler, dongle) != coder)
		pthread_cond_wait(&dongle->dongle_cond, &dongle->dongle_mutex);
	dongle->is_taken = true;
	pop(dongle, coder);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}

void unlock_mutex(t_dongles *dongle, t_coder *coder)
{
	(void)coder;
	pthread_mutex_lock(&dongle->dongle_mutex);
	dongle->dongle_avaible = dongle->dongle_cooldown + get_current_time();
	dongle->is_taken = false;
	pthread_cond_broadcast(&dongle->dongle_cond);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}

t_coder *turn(char *str, t_dongles *dongle)
{
	// printf("dongle avaible = %lld et get_current_time() = %lld\n", dongle->dongle_avaible, get_current_time());
	if(dongle->dongle_avaible >= get_current_time())
		return(NULL);
    if(strcmp(str, "fifo") == 0)
		return(dongle->queue[0]);
	else
	{
		if(!dongle->queue[1])
			return(dongle->queue[0]);
		if(dongle->queue[0]->last_compile <= dongle->queue[1]->last_compile)
			return(dongle->queue[0]);
		else
			return(dongle->queue[1]);
	}
	return(NULL);
}

void push(t_dongles *dongle, t_coder *coder)
{
	if(dongle->queue[0] && dongle->queue[1])
		fprintf(stderr, "Queue Push Error\n");
	
	else if(dongle->queue[0])
		dongle->queue[1] = coder;
	
	else
		dongle->queue[0] = coder;
}

void pop(t_dongles *dongle, t_coder *coder)
{
	if(!dongle->queue[0] && !dongle->queue[1])
		fprintf(stderr, "Queue Pop Error\n");
	
	if(dongle->queue[1] == coder)
		dongle->queue[1] = NULL;
	
	if(dongle->queue[0] == coder)
		dongle->queue[0] = dongle->queue[1];
}