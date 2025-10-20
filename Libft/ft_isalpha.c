/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:37:53 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 17:02:26 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// int main(void)
// {
//     printf("%d ... %d\n",ft_isalpha('a'),isalpha('a'));
//     printf("%d ... %d\n",ft_isalpha('A'),isalpha('A'));
//     printf("%d ... %d\n",ft_isalpha('/'),isalpha('/'));
//     printf("%d ... %d\n",ft_isalpha('9'),isalpha('9'));
//     printf("%d ... %d\n",ft_isalpha('%'),isalpha('%'));
//     printf("%d ... %d\n",ft_isalpha(127),isalpha(127));
//     printf("%d ... %d\n",ft_isalpha(5),isalpha(5));
//     printf("%d ... %d\n",ft_isalpha(32),isalpha(32));
// }
