/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carl <carl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:07:42 by carl              #+#    #+#             */
/*   Updated: 2025/11/22 02:08:26 by carl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"



bool check_file(char *filename)
{
	int	check;
	check = access(filename, F_OK);
	if (check == -1)
		return (perror("fichier invalide"), false);
	else
		return (printf("fichier valide\n"), true);
}

int main() 
{
	int pipefd[2];
	int first_fd;
	int second_fd;
	char *cmd1[] = {"cat", NULL};
	char *cmd2[] = {"wc", "-l", NULL};
	pid_t pid1;
	pid_t pid2;
    extern char **environ;
	char *argv[] = {"nom exec","text.txt", "ls -l", "wc -l", "result.txt",NULL};
    // char *path = ft_strjoin("/bin/", argv[2]);

	
    if (!check_file(argv[1]))
		exit (EXIT_FAILURE);
	if (!check_file(argv[4]))
		exit (EXIT_FAILURE);
	first_fd = open(argv[1],O_RDONLY);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror ("fork");
		exit (EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		first_fd = open(argv[1],O_RDONLY);
		close(pipefd[0]);
		dup2(first_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execve("/bin/cat", cmd1, environ);	
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		second_fd = open(argv[4], O_WRONLY | O_TRUNC);
		if (second_fd == -1)
		{
   	 		perror("open");
    		exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(second_fd, STDOUT_FILENO);
		close(pipefd[0]);
		execve("/bin/wc", cmd2, environ);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
    return (0);
}
