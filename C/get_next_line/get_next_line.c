/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:31:36 by carl              #+#    #+#             */
/*   Updated: 2025/10/28 15:22:55 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_take_stock(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!line)
		return (NULL);
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	return (line);
	
}

char	*ft_take_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		line[i] = buffer[i++];
	line[i] = '\0';
	return (line);
}

int ft_chr_n(char *buffer)
{
	int i = 0;
	if(!buffer)
		return 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// char *ft_get_line(buffer)
// {
	
// }

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*temp;
    char		buffer[BUFFER_SIZE + 1];
	char		*line;
    ssize_t		bytes_read;
	int			n_find;
	
	bytes_read = 1;
	stock = NULL;
	while (bytes_read > 0 && !ft_chr_n(stock))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
		if(bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			temp = stock;
   			stock = ft_strjoin(temp, buffer);
		}
	}
	line = ft_take_line(stock);
	stock = ft_take_stock(stock);
	return (line);
}

int main()
{
	int fd = open("text.txt",O_RDONLY);

	char *test = get_next_line(fd);
	printf("%s\n",test);
}