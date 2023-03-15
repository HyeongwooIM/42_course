/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:10:08 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:17:55 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_last_eat));
	pthread_mutex_destroy(&(info->print));
}

int	ft_usleep(int sleep_utime)
{
	struct timeval	start_time;
	struct timeval	now_time;

	if (gettimeofday(&start_time, NULL) < 0)
		return (printf("get time error.\n"));
	while (1)
	{
		if (gettimeofday(&now_time, NULL) < 0)
			return (printf("get time error.\n"));
		if ((now_time.tv_usec - start_time.tv_usec) > sleep_utime)
			break ;
	}
	return (0);
}

long long	init_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) < 0)
		return (printf("get time error.\n"));
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	act_ing(t_philo *philo, long long time)
{
	long long	start_time;

	start_time = init_time();
	while ((init_time() - start_time < time))
	{
		if ((long long)philo->info->die_time < \
		init_time() - philo->time_last_eat)
			break ;
		usleep(150);
	}
}

void	print_philo(t_info *info, int id, int status)
{
	long long	now_time;

	pthread_mutex_lock(&(info->print));
	now_time = init_time() - info->start_time;
	if (!check_death(info))
	{
		if (status == FORK)
			printf("%lld %d has taken a fork\n", now_time, id);
		else if (status == EAT)
			printf("%lld %d is eating\n", now_time, id);
		else if (status == SLEEP)
			printf("%lld %d is sleeping\n", now_time, id);
		else if (status == THINK)
			printf("%lld %d is thinking\n", now_time, id);
		else if (status == DIE)
		{
			printf("%lld %d died\n", now_time, id);
			pthread_mutex_lock(&(info->check_death));
			info->die_flag = 1;
			pthread_mutex_unlock(&(info->check_death));
		}
	}
	pthread_mutex_unlock(&(info->print));
}
