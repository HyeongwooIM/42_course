#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void print_fd2(char *str)
{
	int i = 0;
	while (str[i]) i++;
	write(2, str, i);
}

int ft_execute(char **av, char** env, int i, int tmp_fd)
{
	av[i] = NULL;
	close(tmp_fd);
	execve(av[0], av, env);
	print_fd2("error: cannot execute ");
	print_fd2(av[0]);
	print_fd2("\n");
	return 1;
}

int main(int ac, char** av, char**env) {
	int fd[2];
	int i = 0;
	int pid = 0;
	int tmp_fd = dup(0);

	(void)ac;
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				print_fd2("error: cd: bad arguments\n");
			else if (chdir(av[1]) != 0)
			{
				print_fd2("error: cd: cannot change directory to ");
				print_fd2(av[1]);
				print_fd2("\n");
			}
		}
		else if (av != &av[i] && (av[i] == 0 || strcmp(av[i], ";") == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, 0);
				if (ft_execute(av, env, i, tmp_fd))
					return 1;
			}
			else
			{
				waitpid(-1, 0, 0);
				close(tmp_fd);
				tmp_fd = dup(0);
			}
		}
		else if (av != &av[i] && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, 0);
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (ft_execute(av, env, i, tmp_fd))
					return 1;
			}
			else
			{
				waitpid(-1, 0, 0);
				close(tmp_fd);
				tmp_fd = dup(fd[0]);
				close(fd[0]);
				close(fd[1]);
			}
		}
	}
	close(tmp_fd);
	return 0;
}