/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 21:41:21 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/09 22:57:49 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

bool	args_checking(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 9)
	{
		fprintf(stderr, "Error: Invalid number of argument\n Usage: ");
		fprintf(stderr, NB_CODERS BURNOUT COMPILE DEBUG REFACTOR);
		fprintf(stderr, NB_COMPILES DONGLE SCHELUDER);
		return(false);
	}

	while (i < argc - 1)
	{
		if (atoi(argv[i]) <= 0)
		{
			fprintf(stderr, "Error: %s have to be a positive integer\n", argv[i]);
			return(false);
		}
		i++;
	}
	if (strcmp(argv[i], "fifo") == 0 || strcmp(argv[i], "edf") == 0)
		return(true);
	
	fprintf(stderr, "Error: '%s' must be 'fifo' or 'edf'\n", argv[i]);
	return(false);
}
