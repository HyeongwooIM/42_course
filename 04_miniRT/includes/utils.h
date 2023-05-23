/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 03:09:29 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 17:03:20 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# include "rt_struct.h"
# include "mlx.h"

int			camera_moving(int keycode, t_scene *scene);

void		mlx_initialize(t_mlx *mlx, t_scene *scene);
int			on_destroy(int key_num, t_mlx *mlx);
int			key_hook(int keycode, t_scene *scene);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);

t_vector	vec3(double x, double y, double z);
t_coord_v	point3(double x, double y, double z);
t_color_v	color3(double r, double g, double b);
double		vlength2(t_vector vec);
double		vlength(t_vector vec);
t_vector	vplus(t_vector vec, t_vector vec2);
t_vector	vplus_(t_vector vec, double x, double y, double z);
t_vector	vminus(t_vector vec, t_vector vec2);
t_vector	vminus_(t_vector vec, double x, double y, double z);
t_vector	vmult(t_vector vec, double t);
t_vector	vmult_(t_vector vec, t_vector vec2);
t_vector	vdivide(t_vector vec, double t);
double		vdot(t_vector vec, t_vector vec2);
t_vector	vcross(t_vector vec, t_vector vec2);
t_vector	vunit(t_vector vec);
t_vector	vmin(t_vector vec1, t_vector vec2);

#endif