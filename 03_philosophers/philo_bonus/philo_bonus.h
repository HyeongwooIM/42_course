/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:20 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:29:27 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_info
{
	pid_t			*pid;
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				max_eat;
	long long		start_time;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*check_last_eat;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long long		time_last_eat;
	pthread_t		thread;
	t_info			*info;
}	t_philo;

void		print_philo(t_info *info, int id, int status);
void		kill_pids(t_info *info, int id);
void		ft_error(char *message);
long long	init_time(void);
void		free_process(t_info *info, t_philo *philo);
int			ft_atoi(const char *s);
void		wait_time(long long time);
int			init_process(t_info *info, t_philo *philo);

#endif
