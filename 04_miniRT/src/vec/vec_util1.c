/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:53:10 by him               #+#    #+#             */
/*   Updated: 2023/05/19 16:33:57 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	vec3(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_coord_v	point3(double x, double y, double z)
{
	t_coord_v	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color_v	color3(double r, double g, double b)
{
	t_color_v	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	vector_set(t_vector *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vector	vmin(t_vector vec1, t_vector vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}
