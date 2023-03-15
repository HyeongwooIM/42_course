/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:49 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:28:49 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	run_philo(t_info *info, t_philo *philo)
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
