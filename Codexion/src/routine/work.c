/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/25 17:12:49 by caaubert         ###   ########.fr       */
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
	coder->last_compile = get_current_time();
	while(*coder->all_alive && !project_finish(coder->data))
	{
		if(coder->id % 2 == 0)
		{
			lock_mutex(coder->r_dongle, coder);
			ft_message("has taken a dongle", coder);
			lock_mutex(coder->l_dongle, coder);
			ft_message("has taken a dongle", coder);
		}
		else
		{
			lock_mutex(coder->l_dongle, coder);
			ft_message("has taken a dongle", coder);
			lock_mutex(coder->r_dongle, coder);
			ft_message("has taken a dongle", coder);
		}
		compiling(coder);
		coder->actual_compiles++;
		pthread_cond_broadcast(coder->finish_cond);
		unlock_mutex(coder->r_dongle, coder);
		unlock_mutex(coder->l_dongle, coder);
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