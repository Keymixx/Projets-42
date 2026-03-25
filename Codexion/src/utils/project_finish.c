/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:36:56 by caaubert          #+#    #+#             */
/*   Updated: 2026/03/25 16:57:41 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

int	project_finish(t_data *data)
{
	int	i;
	int nb_coders;

	i = 0;
	nb_coders = data->number_of_coders;
	while(i < nb_coders)
	{
		if (data->coders[i]->actual_compiles < data->compiles_required)
		{
			return(0);
		}
		i++;
	}
	return(1);
}