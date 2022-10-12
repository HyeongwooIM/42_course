/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:46:30 by him               #+#    #+#             */
/*   Updated: 2022/10/12 20:50:01 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line_len(t_param *param)
{
	t_map	*map;
	int		len;

	len = 0;
	map = param->map;
	while (map)
	{
		map = map->next;
		len++;
	}
	return (len);
}

void	check_map(t_param *param)
{
	int	line_num;

	line_num = check_line_len(param);
}
