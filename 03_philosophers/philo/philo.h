/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:41:01 by woohyeong         #+#    #+#             */
/*   Updated: 2023/03/08 10:13:05 by woohyeong        ###   ########.fr       */
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
# define UNTAKE 0
# define TAKE 1

typedef struct s_info
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	long long		start_time;
	int				die_flag;
	int				full_philo;
	int				fork_list[1000];
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

long long	init_time(void);
void	run_philo(t_philo *philo, t_info *info);
int		check_death(t_info *info);
void	print_philo(t_info *info, int id, int status);
void	act_ing(t_philo *philo, long long time);
int		ft_usleep(int sleep_utime);



# endif