/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:34:47 by him               #+#    #+#             */
/*   Updated: 2023/05/30 12:47:19 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "../mlx/mlx.h"
#include "parse.h"
#include "rt_struct.h"
#include "scene.h"
#include "trace.h"
#include "utils.h"

void	raytracing(t_scene *scene, t_mlx *mlx)
{
	int			i;
	int			j;
	t_color_v	pixel_color;

	j = HEIGHT - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			scene->ray = ray_primary(&scene->camera, i, j);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(mlx, i, HEIGHT - 1 - j, \
			create_trgb(0, pixel_color.x, pixel_color.y, pixel_color.z));
			++i;
		}
		--j;
	}
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlx;

	if (is_valid_input(argc, argv))
		return (1);
	if (read_file_init_struct(argv[1], &scene))
		return (1);
	camera_init(&scene.camera);
	mlx_initialize(&mlx, &scene);
	scene.mlx = &mlx;
	raytracing(&scene, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}
