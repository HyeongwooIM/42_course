/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:41:01 by woohyeong         #+#    #+#             */
/*   Updated: 2023/02/14 16:16:00 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_info
{
	int				philo_num;
	int				die;
	int				eat;
	int				sleep;
	int				max_eat;
	long long		start_time;
	int				die_flag;
	int				full_philo;
	pthread_t		monitor_thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	check_death;
	pthread_mutex_t	check_full;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	print;
} t_info;

typedef struct s_philo
{
	int				id;
	int				fork_right;
	int				fork_left;
	int				num_eat;
	long long		time_last_eat;
	pthread_t		thread;
	t_info			*info;
} t_philo;

# endif