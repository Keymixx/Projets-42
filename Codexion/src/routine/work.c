/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/23 15:50:23 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void compiling(t_coder *coder);
void debugging(t_coder *coder);
void refactoring(t_coder *coder);

void *work(void *arg)
{
	t_coder *coder;
	
	coder = (t_coder *)arg;
	pthread_cond_broadcast(coder->finish_cond);
	if(coder->id % 2 == 0)
		ft_usleep(200, coder);
	coder->last_compile = get_current_time();
	while(*coder->all_alive && !project_finish(coder->data))
	{
		if(pthread_mutex_lock(&coder->r_dongle->dongle_mutex) != 0)
			printf("ERROR R\n");
		ft_message("has taken a dongle", coder);
		if(pthread_mutex_lock(&coder->l_dongle->dongle_mutex) != 0)
			printf("ERROR L\n");
		ft_message("has taken a dongle", coder);
		compiling(coder);
		coder->actual_compiles++;
		pthread_cond_broadcast(coder->finish_cond);
		pthread_mutex_unlock(&coder->r_dongle->dongle_mutex);
		pthread_mutex_unlock(&coder->l_dongle->dongle_mutex);
		debugging(coder);
		refactoring(coder);
	}
	return NULL;
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