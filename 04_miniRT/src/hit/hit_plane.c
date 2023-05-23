/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:00 by him               #+#    #+#             */
/*   Updated: 2023/05/19 16:33:57 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_plane(t_node *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	numrator;
	double	denominator;
	double	root;

	pl = pl_obj->content;
	denominator = vdot(ray->dir, pl->vector);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numrator = vdot(vminus(pl->coord, ray->origin), pl->vector);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal = pl->vector;
	if (!(vdot(ray->dir, rec->normal) < 0))
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = pl->rgb;
	return (TRUE);
}
