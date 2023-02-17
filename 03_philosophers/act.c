/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:42:09 by woohyeong         #+#    #+#             */
/*   Updated: 2023/02/17 18:15:04 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
	print_philo(info, philo->id, FORK);
	pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
	print_philo(info, philo->id, FORK);
	// if (check_death(info))
	// {
	// 	pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
	// 	pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
	// 	return (1);
	// }
	print_philo(info, philo->id, EAT);
	pthread_mutex_lock(&(info->check_last_eat));
	philo->time_last_eat = init_time();
	pthread_mutex_unlock(&(info->check_last_eat));
	philo->num_eat += 1;
	if (philo->num_eat =	= info->max_eat)
	{
		pthread_mutex_lock(&(info->check_full));
		info->full_philo += 1;
		pthread_mutex_unlock(&(info->check_full));
	}
	wait_time(info->eat, philo);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
	return (0);
}