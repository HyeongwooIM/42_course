/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:45:39 by him               #+#    #+#             */
/*   Updated: 2022/10/20 09:54:00 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_change(t_param *param, int keycode)
{
	if (keycode == KEY_W)
	{
		param->p = mlx_xpm_file_to_image \
		(param->mlx_ptr, "img/up.xpm", &param->img_width, &param->img_height);
	}
	else if (keycode == KEY_S)
	{
		param->p = mlx_xpm_file_to_image \
		(param->mlx_ptr, "img/down.xpm", &param->img_width, &param->img_height);
	}
	else if (keycode == KEY_A)
	{
		param->p = mlx_xpm_file_to_image \
		(param->mlx_ptr, "img/left.xpm", &param->img_width, &param->img_height);
	}
	else if (keycode == KEY_D)
	{
		param->p = mlx_xpm_file_to_image (param->mlx_ptr, \
		"img/right.xpm", &param->img_width, &param->img_height);
	}
}
