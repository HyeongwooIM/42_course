/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:32:21 by him               #+#    #+#             */
/*   Updated: 2022/10/20 15:13:27 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_item(t_param *param)
{
	t_map	*map;
	char	*str;

	map = param->map;
	while (map)
	{
		str = map->line;
		while (*str != '\n' && *str != '\0')
		{
			if (*str == 'E')
				param->e_num++;
			else if (*str == 'P')
				param->p_num++;
			else if (*str == 'C')
				param->c_num++;
			else if (*str != '1' && *str != '0')
				error_exit("map 정의되지 않은 item");
			str++;
		}
		map = map->next;
	}
	if (param->e_num != 1 || param->p_num != 1 || param->c_num < 1)
		error_exit("item 수 확인");
}

void	check_wall(t_param *param, size_t map_len)
{
	size_t	line_num;
	size_t	last_line;
	t_map	*map;

	line_num = 0;
	last_line = map_len;
	map = param->map;
	while (map)
	{
		if (line_num == 0 || line_num == last_line - 1)
			top_bottom_check(map->line);
		else
			middle_check(map->line);
		line_num++;
		map = map->next;
	}
}

size_t	check_map_len(t_param *param)
{
	t_map	*map;
	size_t	now_len;
	size_t	len;
	size_t	map_len;

	len = 0;
	now_len = 0;
	map_len = 0;
	map = param->map;
	len = ft_strlen(map->line);
	map_len++;
	map = map->next;
	while (map)
	{
		if (len != ft_strlen(map->line))
			error_exit("지도 길이 불일치");
		map = map->next;
		map_len++;
	}
	return (map_len);
}

void	check_map(t_param *param)
{
	size_t	map_len;

	map_len = check_map_len(param);
	param->win_height = map_len * param->img_height;
	param->win_width = (ft_strlen(param->map->line)) * param->img_width;
	check_wall(param, map_len);
	check_map_item(param);
}
