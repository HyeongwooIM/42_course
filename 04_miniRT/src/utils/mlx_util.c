/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:15:47 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/30 12:47:21 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "rt_struct.h"
#include "scene.h"
#include "trace.h"
#include "utils.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length
			+ x * (mlx->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
		exit(EXIT_FAILURE);
	if (camera_moving(keycode, scene))
	{
		camera_init(&scene->camera);
		raytracing(scene, scene->mlx);
		mlx_put_image_to_window(scene->mlx->mlx, \
			scene->mlx->win, scene->mlx->img, 0, 0);
	}
	return (0);
}

int	on_destroy(int key_num, t_mlx *mlx)
{
	(void)key_num;
	(void)mlx;
	exit(EXIT_FAILURE);
	return (0);
}

void	mlx_initialize(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	if (!mlx->win)
		exit(EXIT_FAILURE);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		exit(EXIT_FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->img,
			&mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	mlx_key_hook(mlx->win, key_hook, scene);
	mlx_hook(mlx->win, 17, 0, on_destroy, &mlx);
}
