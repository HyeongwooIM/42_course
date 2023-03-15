/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:22:35 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:27:50 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *message)
{
	printf("[Error] %s\n", message);
	exit(EXIT_FAILURE);
}

long long	init_time(void)
{
	struct timeval	tp;

	if (gettimeofday(&tp, NULL) < 0)
		return (printf("[Error] Can't get time\n"));
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	free_process(t_info *info, t_philo *philo)
{
	sem_close(info->fork);
	sem_close(info->print);
	sem_close(info->check_last_eat);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("check_last_eat");
	free(philo);
	free(info->pid);
}

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
		if ((sign > 0 && result * sign > INT_MAX) || \
			(sign < 0 && result * sign < INT_MIN))
			return (-1);
		s++;
	}
	return (result * sign);
}

void	wait_time(long long time)
{
	long long	start_time;

	start_time = init_time();
	while ((init_time() - start_time < time))
		usleep(250);
}
