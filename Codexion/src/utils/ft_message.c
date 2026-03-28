/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:47:46 by carl              #+#    #+#             */
/*   Updated: 2026/03/28 10:37:01 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void ft_message(char *str, t_coder *coder)
{       
    long long current_time;
    
    current_time = get_current_time() - *coder->time;
	pthread_mutex_lock(coder->death_mutex);
    if(*coder->all_alive != 0)
        printf("%lld %d %s\n",current_time ,coder->id, str);
    pthread_mutex_unlock(coder->death_mutex);
}