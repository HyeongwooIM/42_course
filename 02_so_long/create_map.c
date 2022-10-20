/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:33:50 by him               #+#    #+#             */
/*   Updated: 2022/10/20 10:51:07 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img(char a, t_param *param, int x, int y)
{
	if (a == '0')
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->g, x, y);
	else if (a == '1')
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->g, x, y);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->w, x, y);
	}
	else if (a == 'P' || a == 'C' || a == 'E')
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->g, x, y);
		if (a == 'P')
			mlx_put_image_to_window \
			(param->mlx_ptr, param->win_ptr, param->p, x, y);
		else if (a == 'C')
			mlx_put_image_to_window \
			(param->mlx_ptr, param->win_ptr, param->c, x, y);
		else if (a == 'E')
			mlx_put_image_to_window \
			(param->mlx_ptr, param->win_ptr, param->e, x, y);
	}
}

void	create_map(t_param *param)
{
	t_map	*map;
	char	*str;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = param->map;
	while (map)
	{
		str = map->line;
		while (*str != '\n')
		{
			create_img(*str, param, x, y);
			str++;
			x += param->img_width;
		}
		map = map->next;
		x = 0;
		y += param->img_height;
	}
}
