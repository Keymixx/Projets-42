/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:47:46 by carl              #+#    #+#             */
/*   Updated: 2026/03/16 00:12:41 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

void ft_message(char *str, t_coder coder)
{
    pthread_mutex_lock(&coder.message);
    printf("%d %s",coder.id, str);
    pthread_mutex_unlock(&coder.message);
}