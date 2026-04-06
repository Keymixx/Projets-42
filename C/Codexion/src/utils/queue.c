/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:41:16 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/30 16:46:23 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void	push(t_dongles *dongle, t_coder *coder)
{
	long long	deadline;

	deadline = coder->last_compile + coder->time_to_burnout;
	coder->deadline = deadline;
	if (!dongle->queue[0])
		dongle->queue[0] = coder;
	else if (strcmp(dongle->scheduler, "fifo") == 0)
		dongle->queue[1] = coder;
	else
	{
		if (coder->deadline < dongle->queue[0]->deadline)
		{
			dongle->queue[1] = dongle->queue[0];
			dongle->queue[0] = coder;
		}
		else
			dongle->queue[1] = coder;
	}
}

void	pop(t_dongles *dongle)
{
	dongle->queue[0] = dongle->queue[1];
	dongle->queue[1] = NULL;
}

int	your_turn(t_coder *coder, t_dongles *dongle)
{
	if (coder == dongle->queue[0])
		return (1);
	else
		return (0);
}

void	take_dongle(t_coder *coder, t_dongles *dongle)
{
	struct timespec	ts;

	pthread_mutex_lock(&dongle->dongle_mutex);
	push(dongle, coder);
	while (*coder->all_alive != 0 && (!your_turn(coder, dongle)
			|| dongle->is_taken || dongle->dongle_avaible > get_current_time()))
	{
		ts.tv_sec = dongle->dongle_avaible / 1000;
		ts.tv_nsec = (dongle->dongle_avaible % 1000) * 1000000;
		pthread_cond_timedwait(&dongle->dongle_cond, &dongle->dongle_mutex,
			&ts);
	}
	pop(dongle);
	ft_message("has taken a dongle", coder);
	dongle->is_taken = true;
	pthread_mutex_unlock(&dongle->dongle_mutex);
}
