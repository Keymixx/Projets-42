/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:31:36 by carl              #+#    #+#             */
/*   Updated: 2025/10/28 02:43:56 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_take_remind(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	while (buffer[i])
		line[i] = buffer[i++];
	line[i] = '\0';
	return (line);
	
}

char	*ft_take_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] != '\n')
		line[i] = buffer[i++];
	line[i] = '\0';
	return (line);
}

int ft_chr_n(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
    char		buffer[BUFFER_SIZE];
	char		*line;
    ssize_t		bytes_read;
	int			n_find;
	
	n_find = 0;
	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	if (bytes_read == 0)
		return (NULL);;
	while (bytes_read > 0 && n_find == 0)
	{
		buffer[bytes_read + 1] = '\0'; 
		reminder = ft_strjoin(reminder,buffer);
		if (ft_chr_n(buffer))
		{
			line = ft_strjoin(line ,ft_take_line(buffer));
			reminder = ft_take_remind(buffer);
			n_find++;
		}
		else
		{
			line = ft_strjoin(line,buffer);
			printf("%s\n",line);
		}
		if (n_find == 0)
    		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	return (line);
}

int main()
{
	int fd = open("text.txt",O_RDONLY);

	char *test = get_next_line(fd);
	printf("%s\n",test);
}