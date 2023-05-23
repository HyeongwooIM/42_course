/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:54:59 by him               #+#    #+#             */
/*   Updated: 2023/05/19 16:33:57 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_ray	ray(t_coord_v origin, t_vector dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vunit(dir);
	return (ray);
}

t_coord_v	ray_at(t_ray *ray, double t)
{
	t_coord_v	at;

	at = vplus(ray->origin, vmult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *camera, int x, int y)
{
	t_ray		ray;
	t_vector	width;
	t_vector	height;
	t_vector	ray_vec;

	ray.origin = camera->coord;
	width = vmult(camera->right_normal, (double)x);
	height = vmult(camera->up_normal, (double)y);
	ray_vec = camera->left_bottom;
	ray_vec = vplus(ray_vec, width);
	ray_vec = vplus(ray_vec, height);
	ray_vec = vminus(ray_vec, camera->coord);
	ray_vec = vunit(ray_vec);
	ray.dir = ray_vec;
	return (ray);
}

t_hit_record	record_init(void)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	return (rec);
}

t_color_v	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->objects->head, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
		return (color3(0, 0, 0));
}
