/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:48:59 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/16 18:31:55 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/codexion.h"

void run_startup(t_data data)
{
	int				i;

	monitoring_init(&data);
	coders_init(&data);
	dongle_init(&data);
	
	printf("\n");
	
	i = 0;
	while (i < data.number_of_coders)
	{
		pthread_create(&data.coders[i]->thread, NULL, &work, data.coders[i]);
		i++;
	}
	i = 0;
	while (i < data.number_of_coders)
	{
		pthread_join(data.coders[i++]->thread, NULL);
	}
}

int	main(int argc, char	*argv[])
{
	t_data			data;
	
	if (!args_checking(argc, argv))
		return (0);
	data = get_data(argv);
	if (data.number_of_coders > 1)
		run_startup(data);
	return(0);
}
