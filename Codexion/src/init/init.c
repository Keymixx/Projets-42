/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:41:18 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/15 23:54:45 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"

pthread_mutex_t *dongle_init(t_coder **coders, int nb_coders)
{
	int				i;
	pthread_mutex_t *dongles;
	
	dongles = malloc(sizeof(pthread_mutex_t) * nb_coders);
	i = 0;
	while (i < nb_coders)
		pthread_mutex_init(&dongles[i++], NULL);
	
	coders[0]->l_dongle = &dongles[i - 1];
	coders[0]->r_dongle = &dongles[0];
	i = 1;
	while(i < nb_coders)
	{
		coders[i]->l_dongle = &dongles[i - 1];
		coders[i]->r_dongle = &dongles[i++];
	}
	
	return dongles;
}

t_monitoring monitoring_init(t_rules rules)
{
	t_monitoring manager;

	manager.dongle_cooldown = rules.dongle_cooldown;
	manager.compiles_required = rules.compiles_required;
	manager.scheduler = rules.scheduler;
	pthread_mutex_init(&manager.message, NULL);
	pthread_cond_init(&manager.death, NULL);

	return manager;
}	

t_coder **coders_init(t_rules rules, t_monitoring manager)
{
	int	i;
	t_coder **all_coders;

	i = 0;
	all_coders = malloc(sizeof(t_coder *) * rules.number_of_coders + 1);
	while(i < rules.number_of_coders)
	{
		all_coders[i] = malloc(sizeof(t_coder));
		all_coders[i]->id = i + 1;
		all_coders[i]->time_to_burnout = rules.time_to_burnout;
		all_coders[i]->time_to_compile = rules.time_to_compile;
		all_coders[i]->time_to_debug = rules.time_to_debug;
		all_coders[i]->time_to_refactor = rules.time_to_refactor;
		all_coders[i]->message = &manager.message;
		i++;
	}
	all_coders[i] = NULL;
	return (all_coders);
}
