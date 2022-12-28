/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:39:27 by woohyeong         #+#    #+#             */
/*   Updated: 2022/12/22 17:30:36 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	morintoring(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;
	while (1)
	{
		if (++i >= info->philo_num)
			i = 0;
		if (is_dead(info, &(*philo)[i]))
			break ;
		if (is_full(info))
		{
			printf("everyone is full!\n");
			break ;
		}
	}
}

int	is_dead(t_info *info, t_philo *philo)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(&(info->check_death));
	dead = info->is_dead;
	pthread_mutex_unlock(&(info->check_death));
	if (dead)
		return (dead);
	pthread_mutex_lock(&(info->check_last_eat));
	if (info->die_time < get_time() - philo->last_eat_time)
		dead = 1;
	pthread_mutex_unlock(&(info->check_last_eat));
	if (dead)
	{
		pthread_mutex_lock(&(info->check_death));
		info->is_dead = dead;
		pthread_mutex_unlock(&(info->check_death));
		printf("%lld %d died\n", get_time() - info->start, philo->id + 1);
	}
	return (dead);
}

int	is_full(t_info *info)
{
	int	full;

	full = 0;
	pthread_mutex_lock(&(info->check_full));
	if (info->num_of_pull >= info->philo_num)
		full = 1;
	pthread_mutex_unlock(&(info->check_full));
	return (full);
}

int	philo_start(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		philo[i].last_eat_time = info->start;
		if (pthread_create(&philo[i].thread, 0, philo_act, &philo[i]))
			return (1);
	}
	return (0);
}