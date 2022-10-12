/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:25:13 by him               #+#    #+#             */
/*   Updated: 2022/10/12 20:46:11 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_param *param)
{
	t_map	*temp;
	t_map	*map;

	map = param->map;
	while (map)
	{
		temp = map->next;
		free(map->map_line);
		free(map);
		map = temp;
	}
	free(map);
}

void	copyline(char *str, t_param *param)
{
	t_map	*line;
	t_map	*return_map;

	return_map = param->map;
	line = malloc(sizeof(t_map));
	if (!line)
	{
		all_free(param);
		return ;
	}
	line->next = 0;
	line->map_line = ft_strdup(str);
	if (!param->map)
		param->map = line;
	else
	{
		while (return_map->next)
			return_map = return_map->next;
		return_map->next = line;
	}
}

int	get_map(t_param *param)
{
	char	*str;

	str = get_next_line(param->fd);
	while (str != NULL)
	{
		copyline(str, param);
		free(str);
		str = get_next_line(param->fd);
	}
	free(str);
	return (1);
}
