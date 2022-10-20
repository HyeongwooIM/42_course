/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:51:59 by him               #+#    #+#             */
/*   Updated: 2022/10/20 10:02:27 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_p(t_param *par)
{
	t_map	*map;
	char	*str;

	map = par->map;
	par->x = 0;
	par->y = 0;
	while (map)
	{
		str = map->line;
		while (*str != '\n' && *str != '\0')
		{
			if (*str == 'P')
				return ;
			str++;
			par->x++;
		}
		map = map->next;
		par->x = 0;
		par->y++;
	}
}

int	get_e(t_param *param)
{
	if (param->c_num == 0)
	{
		param->move_count++;
		printf("The End step : %d", param->move_count);
		exit(0);
		return (0);
	}
	return (1);
}
