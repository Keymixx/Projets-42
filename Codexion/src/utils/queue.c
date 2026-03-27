/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:41:16 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/27 18:47:46 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void push(t_dongles *dongle, t_coder *coder)
{
	long long deadline;

	deadline = coder->last_compile + coder->time_to_burnout;
	coder->deadline = deadline;
	if(!dongle->queue[0])
		dongle->queue[0] = coder;

	else if (strcmp(dongle->scheduler, "fifo") == 0)
		dongle->queue[1] = coder;

	else
	{
		if(coder->deadline < dongle->queue[0]->deadline)
		{
			dongle->queue[1] = dongle->queue[0];
			dongle->queue[0] = coder;
		}
		else
			dongle->queue[1] = coder;
	}
}

