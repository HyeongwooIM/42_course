/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:00:43 by him               #+#    #+#             */
/*   Updated: 2023/05/23 17:01:14 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit_obj(t_node *node, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_flag;

	hit_flag = FALSE;
	if (node->data_type == SPHERE)
		hit_flag = hit_sphere(node, ray, rec);
	else if (node->data_type == PLANE)
		hit_flag = hit_plane(node, ray, rec);
	else if (node->data_type == CYLINDER)
		hit_flag = hit_cylinder(node, ray, rec);
	return (hit_flag);
}

t_bool	hit(t_node *node, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_flag;
	t_hit_record	*temp_rec;

	temp_rec = rec;
	hit_flag = FALSE;
	while (node)
	{
		if (hit_obj(node, ray, temp_rec))
		{
			hit_flag = TRUE;
			temp_rec->tmax = temp_rec->t;
			rec = temp_rec;
		}
		node = node->next;
	}
	return (hit_flag);
}
