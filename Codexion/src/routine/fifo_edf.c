/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_edf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:34:48 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/17 13:30:29 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void schelude(char *str)
{
	
}

void try_lock_dongle(t_coder *coder, pthread_mutex_t *dongle)
{
	int cooldown;

	cooldown = coder->r_dongle->dongle_cooldown;
	ft_usleep(cooldown);
	
}