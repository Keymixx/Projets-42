/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caaubert <caaubert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:31:36 by carl              #+#    #+#             */
/*   Updated: 2025/11/18 01:21:52 by caaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_stock(char *buffer)
{
	int		i;
	int		j;
	char	*stock;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer)
		return (NULL);
	if (i == len)
		return (free(buffer), NULL);
	stock = malloc(sizeof(char) * (ft_strlen_gnl(buffer) - i) + 1);
	if (!stock)
		return (free(buffer), NULL);
	while (buffer[i])
		stock[j++] = buffer[i++];
	stock[j] = '\0';
	return (free(buffer), stock);
}

char	*_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	ft_chr_n(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char *str)
{
	free(str);
	str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_chr_n(stock))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 && !stock)
			return (ft_free(buffer), NULL);
		if (bytes_read < 0 && stock)
			return (ft_free(buffer), free(stock), stock = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			stock = ft_strjoin_gnl(stock, buffer);
	}
	if (!stock)
		return (ft_free(buffer), free(stock), stock = NULL, NULL);
	return (ft_free(buffer), line = _line(stock), stock = _stock(stock), line);
}
