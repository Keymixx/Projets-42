/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:36:47 by caaubert          #+#    #+#             */
/*   Updated: 2025/11/15 23:25:44 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
// int main(void)
// {
//     printf("%d ... %d\n",ft_isalnum('a'),isalnum('a'));
//     printf("%d ... %d\n",ft_isalnum('A'),isalnum('A'));
//     printf("%d ... %d\n",ft_isalnum('/'),isalnum('/'));
//     printf("%d ... %d\n",ft_isalnum('9'),isalnum('9'));
//     printf("%d ... %d\n",ft_isalnum('%'),isalnum('%'));
//     printf("%d ... %d\n",ft_isalnum(127),isalnum(127));
//     printf("%d ... %d\n",ft_isalnum(5),isalnum(5));
//     printf("%d ... %d\n",ft_isalnum(32),isalnum(32));
// }
