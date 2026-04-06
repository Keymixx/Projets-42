// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   test.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/27 23:00:19 by carl              #+#    #+#             */
// /*   Updated: 2025/10/27 23:59:43 by carl             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <string.h>

// int     ft_strlen(const char *str)
// {
//     int i;
    
//     i = 0;
//     while(str[i] && str[i] != '\n')
//         i++;
//     return (i);
// }

// int main()
// {

//     char *test = strdup("");
//     printf("%ld\n",strlen(test));
    
//     // int fd = open("text.txt",O_RDONLY);
//     // ssize_t bytes_read = 1;
//     // char buffer[16];
    
//     // while (bytes_read > 0)
//     // {
//     //     bytes_read = read(fd,buffer,sizeof(buffer) - 1);
//     //     int i = 0;
//     //     while (i < bytes_read)
//     //     {
//     //         printf("%c", buffer[i++]);
//     //     }
//     //     printf("%ld",bytes_read);
//     //     if (buffer[i] == '\0')
//     //         printf("/0");
//     // }
    
// }
// char	*ft_line(char *buffer, ssize_t bytes_read)
// {
// 	int	i;
// 	int j;
// 	char	*line;
// 	static char *reminder;

// 	i = 0;
// 	j = 0;
// 	line = malloc(sizeof(char) * (bytes_read + 1));
// 	if (!line)
// 		return (NULL);
// 	if (reminder)
// 	{
// 		line = ft_strdup(reminder);
// 		j = ft_strlen (reminder);
// 		reminder = NULL;
// 	}
// 	while (buffer[i] != '\n' && i < bytes_read)
// 	{
// 		line[i + j] = buffer[i++];
// 		printf("%d ",i);
// 		printf("%s\n",line);
// 	}
// 	line[i + j] = '\0';
// 	if (i == bytes_read)
// 		return (line);
// 	reminder = ft_strdup(&buffer[i]);
// 	return (line);
// }