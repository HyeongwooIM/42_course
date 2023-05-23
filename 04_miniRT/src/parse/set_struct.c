/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:35:04 by him               #+#    #+#             */
/*   Updated: 2023/05/20 17:25:11 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "parse.h"
#include "rt_struct.h"

int	is_valid_rgb(t_vector *vector)
{
	if (vector->x < 0 || vector->x > 255)
		return (-1);
	if (vector->y < 0 || vector->y > 255)
		return (-1);
	if (vector->z < 0 || vector->z > 255)
		return (-1);
	return (0);
}

int	set_vector(char *str, t_vector *vector)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (!tmp)
		return (-1);
	if (ft_atod(tmp[0], &(vector->x)) || ft_atod(tmp[1], &(vector->y))
		|| ft_atod(tmp[2], &(vector->z)))
	{
		ft_free_2d_array(tmp);
		return (-1);
	}
	ft_free_2d_array(tmp);
	return (0);
}

int	set_ambient(char **data, t_scene *scene)
{
	t_ambient	ambient;

	if (!data || !scene)
		return (-1);
	if (ft_atod(data[1], &(ambient.ratio)))
		return (-1);
	if (set_vector(data[2], &(ambient.rgb)))
		return (-1);
	if (is_valid_rgb(&(ambient.rgb)) || ambient.ratio < 0
		|| scene->dup_check.x != 0)
		return (-1);
	scene->ambient = ambient;
	scene->dup_check.x = 1;
	return (0);
}

int	set_camera(char **data, t_scene *scene)
{
	t_camera	camera;

	if (!data || !scene)
		return (-1);
	if (set_vector(data[1], &(camera.coord)))
		return (-1);
	if (set_vector(data[2], &(camera.dir)))
		return (-1);
	if (ft_atod(data[3], &(camera.fov)))
		return (-1);
	if (is_valid_vector(&(camera.dir)) || camera.fov <= 0
		|| camera.fov >= 180 || scene->dup_check.y != 0)
		return (-1);
	scene->camera = camera;
	scene->dup_check.y = 1;
	return (0);
}

int	set_light(char **data, t_scene *scene)
{
	t_light	light;

	if (!data || !scene)
		return (-1);
	if (set_vector(data[1], &(light.coord)))
		return (-1);
	if (ft_atod(data[2], &(light.ratio)))
		return (-1);
	if (set_vector(data[3], &(light.color)))
		return (-1);
	if (is_valid_rgb(&light.color))
		return (-1);
	if (light.ratio < 0 || scene->dup_check.z != 0)
		return (-1);
	scene->light = light;
	scene->dup_check.z = 1;
	return (0);
}
