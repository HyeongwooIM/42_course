/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:25:25 by him               #+#    #+#             */
/*   Updated: 2023/03/15 14:29:37 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo(t_info *info, int id, int status)
{
	long long	now_time;

	now_time = init_time() - info->start_time;
	sem_wait(info->print);
	if (status == FORK)
		printf("%lld %d has taken a fork\n", now_time, id);
	else if (status == EAT)
		printf("%lld %d is eating\n", now_time, id);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", now_time, id);
	else if (status == THINK)
		printf("%lld %d is thinking\n", now_time, id);
	else if (status == DIE)
	{
		printf("%lld %d died\n", now_time, id);
		return ;
	}
	sem_post(info->print);
}

void	kill_pids(t_info *info, int id)
{
	int	i;

	i = -1;
	while (++i < id)
		kill(info->pid[i], SIGINT);
}
