/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:16:05 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:16:54 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_info *info, t_philo *philo)
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
