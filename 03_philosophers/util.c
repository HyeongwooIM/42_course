/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:16:49 by woohyeong         #+#    #+#             */
/*   Updated: 2022/12/22 17:29:56 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prints(t_info *info, int id, int status)
{
	long long	now;

	pthread_mutex_lock(&(info->check_death));
	if (!info->is_dead)
	{
		pthread_mutex_lock(&(info->print));
		now = get_time() - info->start;
		if (status == FORK)
			printf("%lld %d has taken a fork\n", now, id + 1);
		else if (status == EAT)
			printf("%lld %d is eating\n", now, id + 1);
		else if (status == SLEEP)
			printf("%lld %d is sleeping\n", now, id + 1);
		else if (status == THINK)
			printf("%lld %d is thinking\n", now, id + 1);
		pthread_mutex_unlock(&(info->print));
	}
	pthread_mutex_unlock(&(info->check_death));
}

void	psleep(long long t_sleep)
{
	long long	t_start;
	long long	t_now;

	t_start = get_time();
	while (1)
	{
		t_now = get_time();
		if (t_now - t_start >= t_sleep)
			break ;
		usleep(100);
	}
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, 0) == -1)
		return (1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_atoi(char *str)
{
	long long	num;
	int			index;
	
	index = -1;
	num = 0;
	if (!str)
		return (-1);
	while (str[++index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			num = num * 10 + (str[index] - '0');
		else
			return (-1);
	}
	if (num > 2147483647)
		return (-1);
	return ((int)num);
}
