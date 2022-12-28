/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:24 by woohyeong         #+#    #+#             */
/*   Updated: 2022/12/22 17:53:43 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_info(char **argv, t_info *info)
{
	info->philo_num = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (info->philo_num <= 0 && info->die_time <= 0 && info->eat_time <= 0 && info->sleep_time <= 0)
		return (1);
	if (argv[5])
	{
		info->eat_num = ft_atoi(argv[5]);
		if (info->eat_num <= 0)
			return (1);
	}
	else
		info->eat_num = -1;
	info->num_of_pull = 0;
	info->start = get_time();
	return (0);
}

int	set_philo(t_info	*info, t_philo	**philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * info->philo_num);
	if (!*philo)
	{
		free(info->fork);
		return (1);
	}
	while (++i < info->philo_num)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = i + 1;
		if (i + 1 == info -> philo_num)
			(*philo)[i].right = 0;
		(*philo)[i].eat_num = 0;
		(*philo)[i].last_eat_time = get_time();
		(*philo)[i].status = EAT;
		(*philo)[i].info = info;
	}
	return (0);
}

int	set_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
	if (pthread_mutex_init(&info->fork[i], 0) != 0)
		return (1);
	}	
	if (pthread_mutex_init(&info->print, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_death, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_full, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_last_eat, 0) != 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;
	
	if (argc != 5 && argc != 6)
		return (1);
	if (set_info(argv, &info))
		return (1);
	info.fork = malloc(sizeof(pthread_mutex_t) * info.philo_num);
	if (!info.fork)
		return (1);
	if (set_philo(&info, &philo))
		return (1);
	if (set_mutex(&info))
		return (1);
	if (philo_start(&info, philo))
		return (1);
	morintoring(&info, &philo);
	// free_all(&info, &philo);
	return 0;
}