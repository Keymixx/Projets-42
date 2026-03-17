/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:55 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/17 12:34:10 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"


void push(t_dongles *dongle, int id)
{
	if(dongle->queue[1] && dongle->queue[2])
		fprintf(2, "Queue Push Error\n");
	
	else if(dongle->queue[1])
		dongle->queue[2] = id;
	
	else
		dongle->queue[1] = id;
}

void pop(t_dongles *dongle)
{
	int pop_id;
	
	if(!dongle->queue[1])
		fprintf(2, "Queue Pop Error\n");
	
	else
	{
		pop_id = dongle->queue[1];
		dongle->queue[1] = dongle->queue[2];
		dongle->queue[2] = -1;
	}
	return pop_id;
}