/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:17:11 by him               #+#    #+#             */
/*   Updated: 2023/03/22 13:26:09 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
