/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:36 by woohyeong         #+#    #+#             */
/*   Updated: 2023/03/15 08:45:38 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (((*s >= 9 && *s <= 13) || *s == ' ') && *s)
		s++;
	if ((*s == '+' || *s == '-') && *s)
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
			return (-1);
		result = result * 10 + (*s - '0');
		if ((sign > 0 && result * sign > 2147483647) || \
			(sign < 0 && result * sign < -2147483648))
			return (-1);
		s++;
	}
	return (result * sign);
}


int	set_info(t_info *info, char **argv)
{
	int	i;

	info->philo_num = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (info->philo_num < 1 || info->die_time < 1 || info->eat_time < 1 || info->sleep_time < 1)
		return (1);
	if (argv[5])
	{
		info->max_eat = ft_atoi(argv[5]);
		if (info->max_eat < 1)
			return (1);
	}
	else
		info->max_eat = -1;
	info->full_philo = 0;
	info->die_flag = 0;
	i = -1;
	while (++i < info->philo_num)
		info->fork_list[i] = UNTAKE;	
	return (0);
}

int	init_info(t_info *info)
{
	int	i;

	info->fork = malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (!info->fork)
		return (printf("[Error] Insufficient Memory\n"));
	if ((pthread_mutex_init(&info->check_death, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->check_full, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->check_last_eat, NULL)) != 0)
		return (-1);
	if ((pthread_mutex_init(&info->print, NULL)) != 0)
		return (-1);
	i = -1;
	while (++i < info->philo_num)
	{
		if ((pthread_mutex_init(&info->fork[i], NULL)) != 0)
			return (printf("[Error] Can't init info for Mutex\n"));
	}
	return (0);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;
	int	return_num;

	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return_num = 1;
	else
	{
		i = -1;
		while (++i < info->philo_num)
		{
			(*philo)[i].id = i + 1;
			if (i == 0)
				(*philo)[i].fork_right = info->philo_num - 1;
			else
				(*philo)[i].fork_right = i - 1;
			(*philo)[i].fork_left = i;
			(*philo)[i].num_eat = 0;
			(*philo)[i].info = info;
		}
		return_num = 0;
	}
	return (return_num);	
}

void	free_mutex(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->philo_num) {
		pthread_mutex_destroy(&(info->fork[i]));
	}
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_last_eat));
	pthread_mutex_destroy(&(info->print));
}

int main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (1);
	if (set_info(&info, argv))
		return (1);
	if (init_info(&info) || init_philo(&philo, &info))
		return (1);
	run_philo(philo, &info);
	free_mutex(&info);
	return (0);
}
