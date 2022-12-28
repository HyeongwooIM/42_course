/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:41:38 by woohyeong         #+#    #+#             */
/*   Updated: 2022/12/22 15:27:44 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[philo->left]);
	prints(info, philo->id, FORK);
	pthread_mutex_lock(&info->fork[philo->right]);
	prints(info, philo->id, FORK);
	prints(info, philo->id, EAT);
	pthread_mutex_lock(&info->check_last_eat);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&info->check_last_eat);
	psleep(info->eat_time);
	philo->eat_num += 1;
	pthread_mutex_unlock(&(info->fork[philo->right]));
	pthread_mutex_unlock(&(info->fork[philo->left]));
	philo->status = SLEEP;
}

void	philo_sleep(t_info *info, t_philo *philo)
{
	prints(info, philo->id, SLEEP);
	psleep(info->sleep_time);
	philo->status = THINK;
}

void	philo_think(t_info *info, t_philo *philo)
{
	prints(info, philo->id, THINK);
	philo->status = EAT;
}

void	add_full(t_info *info, int n_eat)
{
	if (n_eat == info->eat_num)
	{
		pthread_mutex_lock(&(info->check_full));
		info->num_of_pull += 1;
		pthread_mutex_unlock(&(info->check_full));
	}
}

void	*philo_act(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 1)
		usleep(100);
	while (1)
	{
		if ((info->eat_num > 0 && philo->eat_num >= info->eat_num)
			|| is_dead(info, philo))
			break ;
		if (philo->status == EAT)
			philo_eat(info, philo);
		else if (philo->status == SLEEP)
			philo_sleep(info, philo);
		else if (philo->status == THINK)
			philo_think(info, philo);
	}	
	add_full(info, philo->eat_num);
	return (0);
}