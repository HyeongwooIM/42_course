/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:42:09 by woohyeong         #+#    #+#             */
/*   Updated: 2023/03/12 01:09:19 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_info *info)
{
	int	die;
	
	pthread_mutex_lock(&(info->check_death));
	die = info->die_flag;
	pthread_mutex_unlock(&(info->check_death));
	return (die);
}

void	change_die_flag(t_info *info)
{
	pthread_mutex_lock(&(info->check_death));
	info->die_flag = 1;
	pthread_mutex_unlock(&(info->check_death));
}

void	set_last_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&(info->check_last_eat));
	philo->time_last_eat = init_time();
	pthread_mutex_unlock(&(info->check_last_eat));
}

void	set_full_philo(t_info *info)
{
	if (info->max_eat == -1)
		return ;
	pthread_mutex_lock(&(info->check_full));
	info->full_philo += 1;
	pthread_mutex_unlock(&(info->check_full));
}

void	take_fork(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[philo->fork_right]);
	info->fork_list[philo->fork_right] = TAKE;
	print_philo(info, philo->id, FORK);
	pthread_mutex_lock(&info->fork[philo->fork_left]);
	info->fork_list[philo->fork_left] = TAKE;
	print_philo(info, philo->id, FORK);
}

void	untake_fork(t_info *info, t_philo *philo)
{
	info->fork_list[philo->fork_right] = UNTAKE;
	pthread_mutex_unlock(&info->fork[philo->fork_right]);
	info->fork_list[philo->fork_left] = UNTAKE;
	pthread_mutex_unlock(&info->fork[philo->fork_left]);
}

int	eat_philo(t_philo *philo)
{
	t_info *info;

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

void *one_philo(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[0]);
	info->fork_list[0] = TAKE;
	print_philo(info, philo->id, FORK);
	while (1)
	{
		if (check_death(info))
		{
			info->fork_list[0] = UNTAKE;
			pthread_mutex_unlock(&info->fork[0]);
			return (0);
		}
		usleep(250);
	}
	return (0);
}

static void	*act_philo(void *philo_ptr)
{
	t_philo *philo;
	
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
	int i;

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
