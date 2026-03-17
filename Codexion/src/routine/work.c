/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/17 16:49:48 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void compiling(t_coder *coder);
void debugging(t_coder *coder);
void refactoring(t_coder *coder);

void *work(void *arg)
{
	t_coder coder;
	
	coder = *(t_coder *)arg;
	if(coder.id % 2 == 0)
		ft_usleep(500, &coder);
	while(true)
	{
		if(pthread_mutex_lock(&coder.r_dongle->dongle_mutex) != 0)
			printf("ERROR R\n");
		ft_message("has taken a dongle", coder);
		if(pthread_mutex_lock(&coder.l_dongle->dongle_mutex) != 0)
			printf("ERROR L\n");
		ft_message("has taken a dongle", coder);
		compiling(&coder);
		pthread_mutex_unlock(&coder.r_dongle->dongle_mutex);
		pthread_mutex_unlock(&coder.l_dongle->dongle_mutex);
		debugging(&coder);
		refactoring(&coder);
	}
}

void compiling(t_coder *coder)
{
	ft_message("is compiling", *coder);
	ft_usleep(coder->time_to_compile, coder);
	coder->last_compile = get_current_time();
}

void debugging(t_coder *coder)
{
	ft_message("is debugging", *coder);
	ft_usleep(coder->time_to_debug, coder);
}

void refactoring(t_coder *coder)
{
	ft_message("is refactoring", *coder);
	ft_usleep(coder->time_to_refactor, coder);
}