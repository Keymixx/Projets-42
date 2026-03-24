/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:55 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/24 18:53:02 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void push(t_dongles *dongle, t_coder *coder);
void pop(t_dongles *dongle, t_coder *coder);
bool your_turn(char *str, t_dongles *dongle, t_coder *coder);

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
	while(!your_turn(dongle->scheduler ,dongle, coder))
		pthread_cond_wait(&dongle->dongle_cond, &dongle->dongle_mutex);
	dongle->is_taken = true;
	pop(dongle, coder);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}

void unlock_mutex(t_dongles *dongle, t_coder *coder)
{
	(void)coder;
	dongle->dongle_avaible = dongle->dongle_cooldown + get_current_time();
	dongle->is_taken = false;
	pthread_cond_broadcast(&dongle->dongle_cond);
}

bool your_turn(char *str, t_dongles *dongle, t_coder *coder)
{
    if(strcmp(str, "fifo") == 0)
    {
        if(dongle->queue[0] == coder && dongle->dongle_avaible <= get_current_time())
            return(true);
        return(false);
    }
    if(dongle->queue[0] == coder)
        return(true);
    if(dongle->queue[1] == NULL)
        return(false);
    if(dongle->queue[0]->last_compile < coder->last_compile)
        return(false);
    return(true);
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