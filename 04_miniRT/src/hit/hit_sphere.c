/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:18 by him               #+#    #+#             */
/*   Updated: 2023/05/19 14:01:47 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "trace.h"
#include "utils.h"

t_bool	hit_sphere_setter(t_sphere_info *sphere, \
t_node *sp_obj, t_ray *ray, t_hit_record *rec)
{
	sphere->sp = sp_obj->content;
	sphere->oc = vminus(ray->origin, sphere->sp->coord);
	sphere->a = vlength2(ray->dir);
	sphere->half_b = vdot(sphere->oc, ray->dir);
	sphere->c = vlength2(sphere->oc) - \
	(sphere->sp->diameter / 2) * (sphere->sp->diameter / 2);
	sphere->discriminant = sphere->half_b * sphere->half_b - \
	sphere->a * sphere->c;
	if (sphere->discriminant < 0)
		return (FALSE);
	sphere->sqrtd = sqrt(sphere->discriminant);
	sphere->root = (-sphere->half_b - sphere->sqrtd) / sphere->a;
	if (sphere->root < rec->tmin || rec->tmax < sphere->root)
	{
		sphere->root = (-sphere->half_b + sphere->sqrtd) / sphere->a;
		if (sphere->root < rec->tmin || rec->tmax < sphere->root)
			return (FALSE);
	}
	rec->t = sphere->root;
	rec->point = ray_at(ray, sphere->root);
	return (TRUE);
}

t_bool	hit_sphere(t_node *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere_info	sphere;

	if (!hit_sphere_setter(&sphere, sp_obj, ray, rec))
		return (FALSE);
	sphere.normal = vminus(rec->point, sphere.sp->coord);
	rec->normal = vdivide(sphere.normal, sphere.sp->diameter);
	if (!(vdot(ray->dir, rec->normal) < 0))
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = sphere.sp->rgb;
	return (TRUE);
}
