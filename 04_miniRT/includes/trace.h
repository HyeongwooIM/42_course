/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 03:08:22 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 17:01:14 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include <math.h>
# include "rt_struct.h"
# include "utils.h"

void		raytracing(t_scene *scene, t_mlx *mlx);

t_ray		ray(t_coord_v origin, t_vector dir);
t_coord_v	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *camera, int x, int y);
t_color_v	ray_color(t_scene *scene);

t_color_v	phong_lighting(t_scene *scene);

t_vector	get_cylinder(t_cylinder *cy, t_vector at_point, double hit_height);

t_bool		hit(t_node *node, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_node *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_node *pl_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_node	*cy_obj, t_ray *ray, t_hit_record *rec);

#endif