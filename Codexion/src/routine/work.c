/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/16 18:44:39 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void compiling(t_coder coder);
void debugging(t_coder coder);
void refactoring(t_coder coder);

void *work(void *arg)
{
	t_coder coder;
	
	coder = *(t_coder *)arg;
	if(coder.id % 2 == 0)
		ft_usleep(500);
	while(true)
	{
		if(pthread_mutex_lock(&coder.r_dongle->dongle_mutex))
			printf("ERROR R\n");
		ft_message("has taken a dongle", coder);
		if(pthread_mutex_lock(&coder.l_dongle->dongle_mutex))
			printf("ERROR L\n");
		ft_message("has taken a dongle", coder);
		compiling(coder);
		debugging(coder);
		refactoring(coder);
		ft_usleep(200);
		pthread_mutex_unlock(&coder.r_dongle->dongle_mutex);
		pthread_mutex_unlock(&coder.l_dongle->dongle_mutex);
	}
}

void compiling(t_coder coder)
{
	ft_message("is compiling", coder);
	ft_usleep(coder.time_to_compile);
}

void debugging(t_coder coder)
{
	ft_message("is debugging", coder);
	ft_usleep(coder.time_to_debug);
}

void refactoring(t_coder coder)
{
	ft_message("is refactoring", coder);
	ft_usleep(coder.time_to_refactor);
}