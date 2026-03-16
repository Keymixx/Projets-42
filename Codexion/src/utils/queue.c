/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:50:55 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/16 17:00:26 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void push(t_dongles dongle, int id)
{
	if(dongle.queue[1] && dongle.queue[2])
		fprintf(2, "Queue Error\n");
	
	else if(dongle.queue[1])
		dongle.queue[2] = id;
	
	else
		dongle.queue[1] = id;
}