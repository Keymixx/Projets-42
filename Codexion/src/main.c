/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:48:59 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/10 01:36:10 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"

t_monitoring monitoring_init(t_rules rules)
{
	t_monitoring manager;

	manager.dongle_cooldown = rules.dongle_cooldown;
	manager.compiles_required = rules.compiles_required;
	manager.scheduler = rules.scheduler;
	pthread_mutex_init(&manager.l_dongle, NULL);
	pthread_mutex_init(&manager.r_dongle, NULL);
	pthread_cond_init(&manager.death, NULL);
}	

t_coder **coders_init(t_rules rules)
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
		i++;
	}
	all_coders[i] = NULL;
	return (all_coders);
}

void run_startup(t_rules rules)
{
	t_coder			**coders;
	t_monitoring	manager;
	
	coders = coders_init(rules);
	manager = monitoring_init(rules);
	
}

int	main(int argc, char	*argv[])
{
	t_rules			rules;
	
	if (!args_checking(argc, argv))
		return (0);
	rules = get_rules(argv);
	if (rules.number_of_coders > 1)
		run_startup(rules);
	return(0);
}
