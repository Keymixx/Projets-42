/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:44:43 by carl              #+#    #+#             */
/*   Updated: 2026/03/28 10:36:19 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/codexion.h"

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(long long milliseconds, t_coder *coder)
{
	(void)coder;
	long long	start;
	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}
