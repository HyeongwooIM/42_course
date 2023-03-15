/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:21:47 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:29:12 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	if (info->philo_num < 1 || info->die_time < 1 || \
	info->eat_time < 1 || info->sleep_time < 1)
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
