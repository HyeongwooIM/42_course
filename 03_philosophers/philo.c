/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:40:36 by woohyeong         #+#    #+#             */
/*   Updated: 2023/02/18 23:41:04 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_info(t_info *info)
{
	int	i;

	info->die_flag = 0;
	info->full_philo = 0;
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

int	set_info(t_info *info, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (info->philo_num < 1 || info->die < 1 || \
		info->eat < 1 || info->sleep < 1)
		return (1);
	if (argv[5])
	{
		info->max_eat = ft_atoi(argv[5]);
		if (info->max_eat < 1)
			return (1);
	}
	else
		info->max_eat = -1;
	return (0);
}

void init_philo(t_philo **philo, t_info *info)
{
		int	i;

	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!philo)
		return (printf("[Error] Insufficient Memory\n"));
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
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (1);
	if (set_info(&info, argv))
		return (1);
	init_info(&info);
	init_philo(&philo, &info);
	run_philo(&philo, &info);
	return (0);
}