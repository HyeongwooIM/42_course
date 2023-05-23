/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:58:21 by him               #+#    #+#             */
/*   Updated: 2023/05/23 10:15:26 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "trace.h"
#include "utils.h"

#include "parse.h"
#include <stdio.h>

t_bool	cy_boundary(t_cylinder *cy, t_vector at_point, t_cylinder_info *c_info)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at_point, cy->coord), vunit(cy->vector));
	max_height = cy->height / 2;
	c_info->hit_height = hit_height;
	if (fabs(c_info->hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

t_bool	hit_cylinder_head(t_node *cy_obj, t_ray *ray, \
t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_vector	head_center;
	double		r;
	double		root;

	cy = cy_obj->content;
	r = cy->diameter / 2;
	head_center = vplus(cy->coord, vmult(vunit(cy->vector), height));
	root = vdot(vminus(head_center, ray->origin), vunit(cy->vector)) \
			/ vdot(ray->dir, vunit(cy->vector));
	if (fabs(r) < fabs(vlength(vminus(head_center, ray_at(ray, root)))))
		return (FALSE);
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->tmax = rec->t;
	rec->normal = vunit(cy->vector);
	if (height < 0)
		rec->normal = vmult(rec->normal, -1);
	if (!(vdot(ray->dir, rec->normal) < 0))
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = cy->rgb;
	return (TRUE);
}

t_bool	hit_cylinder_setter(t_cylinder_info *c_info, \
t_node *cy_obj, t_ray *ray, t_hit_record *rec)
{
	c_info->cy = cy_obj->content;
	c_info->u = ray->dir;
	c_info->o = vunit(c_info->cy->vector);
	c_info->r = c_info->cy->diameter / 2 ;
	c_info->delta_p = vminus(ray->origin, c_info->cy->coord);
	c_info->a = vlength2(vcross(c_info->u, c_info->o));
	c_info->half_b = vdot(vcross(c_info->u, c_info->o), \
	vcross(c_info->delta_p, c_info->o));
	c_info->c = vlength2(vcross(c_info->delta_p, c_info->o)) \
	- pow(c_info->r, 2);
	c_info->discriminant = c_info->half_b * c_info->half_b \
	- c_info->a * c_info->c;
	if (c_info->discriminant < 0)
		return (FALSE);
	c_info->sqrtd = sqrt(c_info->discriminant);
	c_info->root = (-c_info->half_b - c_info->sqrtd) / c_info->a;
	if (c_info->root < rec->tmin || rec->tmax < c_info->root)
	{
		c_info->root = (-c_info->half_b + c_info->sqrtd) / c_info->a;
		if (c_info->root < rec->tmin || rec->tmax < c_info->root)
			return (FALSE);
	}
	return (cy_boundary(c_info->cy, ray_at(ray, c_info->root), c_info));
}

t_bool	hit_cylinder_body(t_node *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder_info	c_info;

	c_info.cy = 0;
	if (!hit_cylinder_setter(&c_info, cy_obj, ray, rec))
		return (FALSE);
	rec->t = c_info.root;
	rec->point = ray_at(ray, c_info.root);
	rec->normal = get_cylinder(c_info.cy, rec->point, c_info.hit_height);
	if (!(vdot(ray->dir, rec->normal) < 0))
		rec->normal = vmult(rec->normal, -1);
	rec->albedo = c_info.cy->rgb;
	return (TRUE);
}

t_bool	hit_cylinder(t_node	*cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	int			hit_flag;

	hit_flag = 0;
	cy = cy_obj->content;
	hit_flag += hit_cylinder_head(cy_obj, ray, rec, cy->height / 2);
	hit_flag += hit_cylinder_head(cy_obj, ray, rec, -(cy->height / 2));
	hit_flag += hit_cylinder_body(cy_obj, ray, rec);
	return (hit_flag);
}
