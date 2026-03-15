/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:34:12 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/10 19:47:33 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"


t_rules get_rules(char *argv[])
{
	t_rules rules;

	rules.number_of_coders = atoi(argv[1]);
	rules.time_to_burnout = atoi(argv[2]);
	rules.time_to_compile = atoi(argv[3]);
	rules.time_to_debug = atoi(argv[4]);
	rules.time_to_refactor = atoi(argv[5]);
	rules.compiles_required = atoi(argv[6]);
	rules.dongle_cooldown = atoi(argv[7]);
	rules.scheduler = argv[8];

	return (rules);
}