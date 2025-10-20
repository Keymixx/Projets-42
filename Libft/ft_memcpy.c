/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:31:13 by caaubert          #+#    #+#             */
/*   Updated: 2025/10/20 18:33:02 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, void *source, size_t size)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if(destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}

// int main(void)
// {
// }