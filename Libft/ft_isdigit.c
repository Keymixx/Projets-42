/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:05:03 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 17:02:36 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1 );
	else
		return (0);
}

// int main(void)
// {
//     printf("%d ... %d\n",ft_isdigit('a'),isdigit('a'));
//     printf("%d ... %d\n",ft_isdigit('A'),isdigit('A'));
//     printf("%d ... %d\n",ft_isdigit('/'),isdigit('/'));
//     printf("%d ... %d\n",ft_isdigit('9'),isdigit('9'));
//     printf("%d ... %d\n",ft_isdigit('%'),isdigit('%'));
//     printf("%d ... %d\n",ft_isdigit(127),isdigit(127));
//     printf("%d ... %d\n",ft_isdigit(5),isdigit(5));
//     printf("%d ... %d\n",ft_isdigit(32),isdigit(32));
// }