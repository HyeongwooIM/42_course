/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:35:09 by him               #+#    #+#             */
/*   Updated: 2023/05/19 16:35:46 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rt_struct.h"

void	print_vector(char *data_str, t_vector *vector)
{
	printf("%s: [%f, %f, %f]\n", data_str, vector->x, vector->y, vector->z);
}

void	print_ambient(t_ambient *ambient)
{
	printf("type: ambient\n");
	printf("ratio: %f\n", ambient->ratio);
	print_vector("rgb", &(ambient->rgb));
}

void	print_camera(t_camera *camera)
{
	printf("type: camera\n");
	print_vector("coordinate", &(camera->coord));
	print_vector("vector", &(camera->dir));
	printf("fov: %f\n", camera->fov);
}

void	print_light(t_light *light)
{
	printf("type: light\n");
	print_vector("vector", &(light->coord));
	printf("ratio: %f\n", light->ratio);
}
