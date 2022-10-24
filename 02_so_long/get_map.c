/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:19:42 by him               #+#    #+#             */
/*   Updated: 2022/10/24 16:16:11 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		error_exit("strdup malloc fail");
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

void	node_copy(char *str, t_param *param)
{
	t_map	*node;
	t_map	*return_map;

	return_map = param->map;
	node = malloc(sizeof(t_map));
	if (!node)
		error_exit("line malloc fail");
	node->next = 0;
	node->line = ft_strdup(str);
	if (!param->map)
		param->map = node;
	else
	{
		while (return_map->next)
			return_map = return_map->next;
		return_map->next = node;
	}
}

void	get_map(t_param *param)
{
	char	*str;

	str = get_next_line(param->fd);
	if (str == 0)
		error_exit("get_next_line return = 0");
	while (str != 0)
	{
		node_copy(str, param);
		free(str);
		str = get_next_line(param->fd);
	}
	free(str);
}
