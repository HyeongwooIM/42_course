/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:31:48 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/09 19:44:54 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "rt_struct.h"
#include "parse.h"

void	print_sphere(t_sphere *sphere)
{
	printf("type: sphere\n");
	print_vector("coordinate", &(sphere->coord));
	printf("diameter: %f\n", sphere->diameter);
	print_vector("rgb", &(sphere->rgb));
}

void	print_plane(t_plane *plane)
{
	printf("type: plane\n");
	print_vector("coordinate", &(plane->coord));
	print_vector("vector", &(plane->vector));
	print_vector("rgb", &(plane->rgb));
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("type: cylinder\n");
	print_vector("coordinate", &(cylinder->coord));
	print_vector("vector", &(cylinder->vector));
	printf("diameter: %f\n", cylinder->diameter);
	printf("height: %f\n", cylinder->height);
	print_vector("rgb", &(cylinder->rgb));
}
