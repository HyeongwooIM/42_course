/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:25:13 by him               #+#    #+#             */
/*   Updated: 2022/10/12 20:15:15 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copyline(char *str, t_param *param)
{
	
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
