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
} t_info;

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long long		time_last_eat;
	pthread_t		thread;
	t_info			*info;
} t_philo;

#endif