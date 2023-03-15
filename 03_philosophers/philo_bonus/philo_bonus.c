#include "philo_bonus.h"

void	ft_error(char *message)
{
	printf("[Error] %s\n", message);
	exit(EXIT_FAILURE);
}

long long	init_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) < 0)
		return (printf("[Error] Can't get time\n"));
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

static void	free_process(t_info *info, t_philo *philo)
{
	sem_close(info->fork);
	sem_close(info->print);
	sem_close(info->check_last_eat);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("check_last_eat");
	free(philo);
	free(info->pid);
}

int	ft_atoi(const char *s)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (((*s >= 9 && *s <= 13) || *s == ' ') && *s)
		s++;
	if ((*s == '+' || *s == '-') && *s)
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
			return (-1);
		result = result * 10 + (*s - '0');
		if ((sign > 0 && result * sign > INT_MAX) || \
			(sign < 0 && result * sign < INT_MIN))
			return (-1);
		s++;
	}
	return (result * sign);
}

void	wait_time(long long time)
{
	long long	start_time;

	start_time = init_time();
	while ((init_time() - start_time < time))
		usleep(250);
}

void	print_philo(t_info *info, int id, int status)
{
	long long	now_time;

	now_time = init_time() - info->start_time;
	sem_wait(info->print);
	if (status == FORK)
		printf("%lld %d has taken a fork\n", now_time, id);
	else if (status == EAT)
		printf("%lld %d is eating\n", now_time, id);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", now_time, id);
	else if (status == THINK)
		printf("%lld %d is thinking\n", now_time, id);
	else if (status == DIE)
	{
		printf("%lld %d died\n", now_time, id);
		return ;
	}
	sem_post(info->print);
}

void	kill_pids(t_info *info, int id)
{
	int	i;

	i = -1;
	while (++i < id)
		kill(info->pid[i], SIGINT);
}

static void	eat_philo(t_info *info, t_philo *philo)
{
	sem_wait(info->fork);
	print_philo(info, philo->id, FORK);
	sem_wait(info->fork);
	print_philo(info, philo->id, FORK);
	print_philo(info, philo->id, EAT);
	philo->num_eat += 1;
	sem_wait(info->check_last_eat);
	philo->time_last_eat = init_time();
	sem_post(info->check_last_eat);
	wait_time(info->eat_time);
	sem_post(info->fork);
	sem_post(info->fork);
}

void	*monitoring(void	*ph)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)ph;
	info = philo->info;
	while (1)
	{
		sem_wait(info->check_last_eat);
		if ((long long)info->die_time < init_time() - philo->time_last_eat)
		{
			sem_post(info->check_last_eat);
			print_philo(info, philo->id, DIE);
			exit(EXIT_FAILURE);
		}
		sem_post(info->check_last_eat);
		usleep(200);
	}
	return (0);
}

void run_philo(t_info *info, t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, &monitoring, philo) != 0)
		exit (EXIT_FAILURE);
	pthread_detach(philo->thread);
	if (!(philo->id % 2))
		wait_time(info->eat_time * 0.5);
	while (1)
	{
		eat_philo(info, philo);
		if (philo->num_eat == info->max_eat)
			break ;
		print_philo(info, philo->id, SLEEP);
		wait_time(info->sleep_time);
		print_philo(info, philo->id, THINK);
	}
	exit (EXIT_SUCCESS);
}

int	init_process(t_info *info, t_philo *philo)
{
	int	i;

	info->pid = malloc(sizeof(pid_t) * info->philo_num);
	if (!info->pid)
		return (-1);
	i = -1;
	while (++i < info->philo_num)
	{
		info->pid[i] = fork();
		if (info->pid[i] < 0)
		{
			kill_pids(info, i);
			return (-1);
		}
		if (info->pid[i] == 0)
			run_philo(info, &philo[i]);
	}
	return (0);
}
void	wait_process(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->philo_num)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_pids(info, info->philo_num);
			usleep(2000);
			sem_post(info->print);
			sem_post(info->check_last_eat);
			break ;
		}
		sem_post(info->print);
		sem_post(info->check_last_eat);
	}
}

int	init_info(t_info *info)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("check_last_eat");
	info->start_time = init_time();
	info->fork = sem_open("fork", O_CREAT, 0644, info->philo_num);
	if (info->fork == SEM_FAILED)
		return (-1);
	info->print = sem_open("print", O_CREAT, 0644, 1);
	if (info->print == SEM_FAILED)
		return (-1);
	info->check_last_eat = sem_open("check_last_eat", O_CREAT, 0644, 1);
	if (info->print == SEM_FAILED)
		return (-1);
	return (0);
}

int	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return (-1);
	i = -1;
	while (++i < info->philo_num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].num_eat = 0;
		(*philo)[i].info = info;
		(*philo)[i].time_last_eat = init_time();
	}
	return (0);
}

int	get_info(char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (info->philo_num < 1 || info->die_time < 1 || info->eat_time < 1 || info->sleep_time < 1)
		return (1);
	if (argv[5])
	{
		info->max_eat = ft_atoi(argv[5]);
		if (info->max_eat < 1)
			return (1);
	}
	else
		info->max_eat = -1;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6) || get_info(argv, &info))
		ft_error("Invalid Arguments");
	if (init_info(&info))
		ft_error("Semaphore open failed");
	if (init_philo(&info, &philo))
		ft_error("Philo init failed");
	if (init_process(&info, philo))
		ft_error("Philo process failed");
	wait_process(&info);
	free_process(&info, philo);
	return (0);
}
