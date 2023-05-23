/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:55:06 by him               #+#    #+#             */
/*   Updated: 2023/05/23 16:59:40 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	shadow(t_node *objs, t_ray ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_len;
	if (hit(objs, &ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color_v	point_light_get(t_scene *scene, t_light *light)
{
	t_color_v	diffuse;
	t_vector	light_dir;
	double		kd;
	double		light_len;
	t_ray		light_ray;

	light_dir = vminus(light->coord, scene->rec.point);
	light_dir = vminus(vminus(light->coord, \
	vmult(vunit(light_dir), EPSILON)), scene->rec.point);
	light_len = vlength(light_dir);
	light_ray = ray(vplus(scene->rec.point, \
	vmult(scene->rec.normal, EPSILON)), light_dir);
	if (shadow(scene->objects->head, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diffuse = vdivide(light->color, 255);
	diffuse = vmult(diffuse, light->ratio);
	diffuse = vmult(diffuse, kd);
	diffuse = vmult_(diffuse, scene->rec.albedo);
	return (diffuse);
}

t_color_v	phong_lighting(t_scene *scene)
{
	t_color_v	rec_color;
	t_color_v	light_color;
	t_color_v	ambient_color;
	t_light		light;

	rec_color = scene->rec.albedo;
	light_color = color3(0, 0, 0);
	light = scene->light;
	light_color = vplus(light_color, point_light_get(scene, &light));
	ambient_color = vdivide(scene->ambient.rgb, 255);
	ambient_color = vmult(ambient_color, scene->ambient.ratio);
	ambient_color = vmult_(ambient_color, rec_color);
	return (vmin(vplus(light_color, ambient_color), color3(255, 255, 255)));
}
