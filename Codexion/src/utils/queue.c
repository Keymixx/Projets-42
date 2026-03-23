/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:55 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/23 17:54:12 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void lock_mutex(t_dongles *dongle, t_coder *coder)
{
	pthread_mutex_lock(&dongle->dongle_mutex);
	if(!dongle->is_taken)
	{
		dongle->is_taken = true;
		return;		
	}
	push(dongle, coder);
	while(!your_turn(c))
		pthread_cond_wait();
	dongle->is_taken = true;
	pop(dongle, coder);
}

void unlock_mutex(t_dongles *dongle, t_coder *coder)
{
	pthread_mutex_unlock(&dongle->dongle_mutex);
	ft_usleep(dongle->dongle_cooldown, coder);
	dongle->is_taken = false;
}

bool algo(char *str, t_dongles dongle, t_coder coder)
{
	if(strcmp(str, "fifo" == 0)
	{
		
	}
}

void push(t_dongles *dongle, t_coder *coder)
{
	if(dongle->queue[1] && dongle->queue[2])
		fprintf(2, "Queue Push Error\n");
	
	else if(dongle->queue[1])
		dongle->queue[2] = coder;
	
	else
		dongle->queue[1] = coder;
}

void pop(t_dongles *dongle, t_coder *coder)
{
	if(!dongle->queue[1] && !dongle->queue[2])
		fprintf(2, "Queue Pop Error\n");
	
	if(dongle->queue[2] == coder)
		dongle->queue[2] = NULL;
	
	if(dongle->queue[1] == coder)
		dongle->queue[1] = dongle->queue[2];
}