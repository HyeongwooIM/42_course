/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:17:40 by him               #+#    #+#             */
/*   Updated: 2022/10/20 10:02:14 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player(t_param *param)
{
	t_map	*map;
	char	*str;

	map = param->map;
	param->x = 0;
	param->y = 0;
	while (map)
	{
		str = map->line;
		while (*str != '\n' && *str != '\0')
		{
			if (*str == 'P')
				return ;
			str++;
			param->x++;
		}
		map = map->next;
		param->x = 0;
		param->y++;
	}
}
