/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:16:31 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:16:46 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_philo(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	take_fork(info, philo);
	if (check_death(info))
	{
		untake_fork(info, philo);
		return (1);
	}
	print_philo(philo->info, philo->id, EAT);
	act_ing(philo, info->eat_time);
	set_last_eat(info, philo);
	untake_fork(info, philo);
	philo->num_eat += 1;
	if (philo->num_eat == info->max_eat)
		set_full_philo(info);
	return (0);
}

void	*act_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->info->philo_num == 1)
		return (one_philo(philo->info, philo));
	if (!(philo->id % 2))
		usleep(250);
	while (1)
	{
		if (check_death(philo->info))
			break ;
		if (eat_philo(philo))
			break ;
		if (check_death(philo->info) || philo->num_eat == philo->info->max_eat)
			break ;
		print_philo(philo->info, philo->id, SLEEP);
		act_ing(philo, philo->info->sleep_time);
		if (check_death(philo->info))
			break ;
		print_philo(philo->info, philo->id, THINK);
		usleep(250);
	}
	return (0);
}

int	check_end(t_info *info, t_philo *philo, int i)
{
	if (info->max_eat != -1)
	{
		pthread_mutex_lock(&(info->check_full));
		if (info->full_philo == info->philo_num)
		{
			change_die_flag(info);
			return (1);
		}
		pthread_mutex_unlock(&(info->check_full));
	}
	pthread_mutex_lock(&(info->check_last_eat));
	if ((long long)info->die_time < init_time() - philo[i].time_last_eat)
	{
		print_philo(info, philo[i].id, DIE);
		pthread_mutex_unlock(&(info->check_last_eat));
		change_die_flag(info);
		return (1);
	}
	pthread_mutex_unlock(&(info->check_last_eat));
	return (0);
}

void	*monitoring(void *philos)
{
	t_philo	*philo;
	t_info	*info;
	int		i;

	philo = (t_philo *)philos;
	info = philo->info;
	i = -1;
	while (1)
	{
		if (++i >= info->philo_num)
			i = 0;
		if (check_end(info, philo, i))
			break ;
	}
	return (0);
}

void	run_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = init_time();
	while (i < info->philo_num)
	{
		philo[i].time_last_eat = init_time();
		if (pthread_create(&philo[i].thread, NULL, act_philo, &philo[i]))
			return ;
		i++;
	}
	if (pthread_create(&info->monitor_thread, NULL, monitoring, philo))
		return ;
	pthread_join(info->monitor_thread, NULL);
	i = -1;
	while (++i < info->philo_num)
		pthread_join(philo[i].thread, NULL);
	return ;
}
