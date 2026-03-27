/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/27 23:55:45 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void cooldown_dongle(t_dongles *dongle);
void compiling(t_coder *coder);
void debugging(t_coder *coder);
void refactoring(t_coder *coder);

void *work(void *arg)
{
	t_coder *coder;
	
	coder = (t_coder *)arg;
	pthread_cond_broadcast(coder->finish_cond);
	coder->last_compile = get_current_time();
	while(*coder->all_alive && !project_finish(coder->data))
	{
		if(coder->id % 2 == 0)
		{
			take_dongle(coder, coder->r_dongle);
			take_dongle(coder, coder->l_dongle);
		}
		else
		{
			take_dongle(coder, coder->l_dongle);
			take_dongle(coder, coder->r_dongle);
		}
		compiling(coder);
		cooldown_dongle(coder->r_dongle);
		cooldown_dongle(coder->l_dongle);
		coder->actual_compiles++;
		pthread_cond_broadcast(coder->finish_cond);
		debugging(coder);
		refactoring(coder);
	}
	return NULL;
}

void cooldown_dongle(t_dongles *dongle)
{
	long long timestamp_dongle;
	
	pthread_mutex_lock(&dongle->dongle_mutex);
	timestamp_dongle = get_current_time() + dongle->dongle_cooldown;
	dongle->dongle_avaible = timestamp_dongle;
	dongle->is_taken = false;
	pthread_cond_broadcast(&dongle->dongle_cond);
	pthread_mutex_unlock(&dongle->dongle_mutex);
}

void compiling(t_coder *coder)
{
	ft_message("is compiling", coder);
	coder->last_compile = get_current_time();
	ft_usleep(coder->time_to_compile, coder);
}

void debugging(t_coder *coder)
{
	ft_message("is debugging", coder);
	ft_usleep(coder->time_to_debug, coder);
}

void refactoring(t_coder *coder)
{
	ft_message("is refactoring", coder);
	ft_usleep(coder->time_to_refactor, coder);
}