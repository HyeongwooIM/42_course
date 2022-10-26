/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:17:51 by woohyeong         #+#    #+#             */
/*   Updated: 2022/10/26 19:25:29 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error_exit("file open error");
	dup2(fd[1], STDOUT_FILENO); //STDOUT_FILENO = 1
	dup2(filein, STDIN_FILENO); //STDIN_FILEIN = 0
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error_exit("file open error");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

void	error_exit(char *str)
{
	printf("%s \n", str);
	exit(1);
}

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;

	if (argc != 5)
		error_exit("arg num error");
	if (pipe(fd) == -1)
		error_exit("pipe error");
	pid = fork();
	if (pid == -1)
		error_exit("fork error");
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
}
