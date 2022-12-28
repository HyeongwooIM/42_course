/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:59 by woohyeong         #+#    #+#             */
/*   Updated: 2022/12/22 17:54:00 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5
typedef struct s_info
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_num;
	int				num_of_pull;
	long long 		start;
	int				is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	check_death;
	pthread_mutex_t	check_full;
	pthread_mutex_t	check_last_eat;
} t_info;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	long long	last_eat_time;
	int			eat_num;
	int			status;
	t_info		*info;
	pthread_t	thread;
	
} t_philo;


//philo.c
void	morintoring(t_info *info, t_philo **philo);
int	philo_start(t_info *info, t_philo *philo);
int	is_full(t_info *info);
int	is_dead(t_info *info, t_philo *philo);

// philo_act.c
void	*philo_act(void *arg);
void	add_full(t_info *info, int n_eat);
void	philo_think(t_info *info, t_philo *philo);
void	philo_sleep(t_info *info, t_philo *philo);
void	philo_eat(t_info *info, t_philo *philo);

// util.c
void	prints(t_info *info, int id, int status);
void	psleep(long long t_sleep);
long long	get_time(void);
int ft_atoi(char *str);

# endif