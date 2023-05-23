/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:24:21 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/20 19:45:50 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "linked_list.h"
#include "parse.h"
#include "rt_struct.h"

int	is_valid_vector(t_vector *vector)
{
	if (vector->x < -1 || vector->x > 1)
		return (-1);
	if (vector->y < -1 || vector->y > 1)
		return (-1);
	if (vector->z < -1 || vector->z > 1)
		return (-1);
	if (vector->x == 0 && vector->y == 0 && vector->z == 0)
		return (-1);
	return (0);
}

int	alloc_sphere(char **data, t_scene *scene)
{
	t_sphere	*sphere;
	t_node		*node;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (-1);
	if (set_vector(data[1], &(sphere->coord))
		|| ft_atod(data[2], &(sphere->diameter))
		|| set_vector(data[3], &(sphere->rgb))
		|| sphere->diameter <= 0 || is_valid_rgb(&(sphere->rgb)))
	{
		free(sphere);
		return (-1);
	}
	node = create_node(sphere, SPHERE);
	list_add_back(scene->objects, node);
	return (0);
}

int	alloc_plane(char **data, t_scene *scene)
{
	t_plane	*plane;
	t_node	*node;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (-1);
	if (set_vector(data[1], &(plane->coord))
		|| set_vector(data[2], &(plane->vector))
		|| set_vector(data[3], &(plane->rgb))
		|| is_valid_vector(&(plane->vector))
		|| is_valid_rgb(&(plane->rgb)))
	{
		free(plane);
		return (-1);
	}
	node = create_node(plane, PLANE);
	list_add_back(scene->objects, node);
	return (0);
}

int	alloc_cylinder(char **data, t_scene *scene)
{
	t_cylinder	*cylinder;
	t_node		*node;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (-1);
	if (set_vector(data[1], &(cylinder->coord))
		|| set_vector(data[2], &(cylinder->vector))
		|| ft_atod(data[3], &(cylinder->diameter))
		|| ft_atod(data[4], &(cylinder->height))
		|| set_vector(data[5], &(cylinder->rgb))
		|| is_valid_vector(&(cylinder->vector)) || cylinder->diameter <= 0
		|| cylinder->height <= 0 || is_valid_rgb(&(cylinder->rgb)))
	{
		free(cylinder);
		return (-1);
	}
	node = create_node(cylinder, CYLINDER);
	list_add_back(scene->objects, node);
	return (0);
}
