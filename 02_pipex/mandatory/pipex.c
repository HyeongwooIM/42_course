/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:54:56 by him               #+#    #+#             */
/*   Updated: 2022/10/25 17:37:56 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error_exit("open error");
	dup2(fd[1], 1);
	dup2(filein, 0);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	
}

void	error_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid;
	t_arg	arg;

	if (argc != 5)
		error_exit("arg error");
	arg.infile = open(argv[1], O_RDONLY);
	if (arg.infile == -1)
		error_exit("file open error");
	arg.outfile = open(argv[4], O_RDONLY);
	if (arg.outfile == -1)
		error_exit("file open error");
	arg.path = get_path(envp);
	if (pipe(fd) == -1)
		error_exit("pipe error");
	pid = fork();
	if (pid == -1)
		error_exit("fork error");
	else if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid);
	return (0);
}

char	*get_path(char **envp)
{
	int		i;
	int		len;
	char	*path;

	i = 0;
	len = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	while (envp[i][len + 5])
		len++;
	path = malloc(sizeof(char) * len + 1);

}
