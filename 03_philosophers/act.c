/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:42:09 by woohyeong         #+#    #+#             */
/*   Updated: 2023/02/14 17:19:07 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_right]);
	print_philo(info, philo->id, FORK);
	pthread_mutex_lock(&philo->info->fork[philo->fork_left]);
	print_philo(info, philo->id, FORK);
	philo->time_last_eat = get_time();
	print_philo(info, philo->id, EAT);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_right]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_left]);
	return (0);
}