/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:58:01 by him               #+#    #+#             */
/*   Updated: 2023/05/20 21:48:17 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "trace.h"
#include "utils.h"

t_vector	get_cylinder(t_cylinder *cy, t_vector at_point, double hit_height)
{
	t_coord_v	hit_center;
	t_vector	normal;

	hit_center = vplus(cy->coord, vmult(vunit(cy->vector), hit_height));
	normal = vminus(at_point, hit_center);
	return (vunit(normal));
}
