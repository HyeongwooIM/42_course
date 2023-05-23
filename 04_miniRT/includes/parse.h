/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:53:37 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/20 19:42:10 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "rt_struct.h"
# include "linked_list.h"

// check_input
int		is_valid_input(int argc, char **argv);
void	check_scene(t_scene *scene);

// read_input
int		read_file_init_struct(char *file, t_scene *scene);

// set_struct
int		is_valid_rgb(t_vector *vector);
int		set_vector(char *str, t_vector *vector);
int		set_ambient(char **data, t_scene *scene);
int		set_camera(char **data, t_scene *scene);
int		set_light(char **data, t_scene *scene);

// alloc_object
int		is_valid_vector(t_vector *vector);
int		alloc_sphere(char **data, t_scene *scene);
int		alloc_plane(char **data, t_scene *scene);
int		alloc_cylinder(char **data, t_scene *scene);

// print_list
void	print_scene(t_scene *scene);

// print_struct
void	print_vector(char *data_str, t_vector *vector);
void	print_ambient(t_ambient *ambient);
void	print_camera(t_camera *camera);
void	print_light(t_light *light);

// print_object
void	print_sphere(t_sphere *sphere);
void	print_plane(t_plane *plane);
void	print_cylinder(t_cylinder *cylinder);

// free_objects
void	free_objects(t_objects *objects);

#endif
