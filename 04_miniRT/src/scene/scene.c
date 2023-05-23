/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:43:03 by him               #+#    #+#             */
/*   Updated: 2023/05/23 10:54:43 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "utils.h"

static double	get_tan(double degree)
{
	double	radian;

	radian = M_PI / 180;
	return (tan(degree * radian));
}

void	camera_init(t_camera *camera)
{
	t_vector	vec_y;
	t_vector	vec_z;
	t_vector	temp;

	vec_y = vec3(0.0, 1.0, 0.0);
	vec_z = vec3(0.0, 0.0, -1.0);
	camera->dir = vunit(camera->dir);
	if (vlength(vcross(vec_y, camera->dir)))
		camera->up_normal = vunit(vcross(camera->dir, vec_y));
	else
		camera->up_normal = vunit(vcross(camera->dir, vec_z));
	camera->right_normal = vunit(vcross(camera->up_normal, camera->dir));
	camera->focal_len = (double)WIDTH / 2 / get_tan(camera->fov / 2);
	temp = vplus(camera->coord, vmult(camera->dir, camera->focal_len));
	temp = vminus(temp, vmult(camera->right_normal, (double)(WIDTH - 1) / 2));
	temp = vminus(temp, vmult(camera->up_normal, (double)(HEIGHT - 1) / 2));
	camera->left_bottom = temp;
}
