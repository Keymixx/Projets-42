/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:06:37 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/16 00:19:26 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void *work(void *arg)
{
	t_coder coder;
	int		i;
	
	coder = *(t_coder *)arg;
	
	while(true)
	{
		pthread_mutex_lock(coder.l_dongle);
		ft_message("has taken a dongle", coder);
		pthread_mutex_lock(coder.r_dongle);
		ft_message("has taken a dongle", coder);
		compiling(coder);
		debugging(coder);
		refactoring(coder);
		pthread_mutex_unlock(coder.l_dongle);
		pthread_mutex_unlock(coder.r_dongle);
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