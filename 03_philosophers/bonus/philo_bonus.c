#include "philo_bonus.h"

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
