/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:33:55 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 16:19:46 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "ft_error.h"
#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include "rt_struct.h"

void	init_scene(t_scene *scene)
{
	t_vector	dup_check;

	dup_check.x = 0;
	dup_check.y = 0;
	dup_check.z = 0;
	scene->dup_check = dup_check;
	scene->objects = ft_calloc(1, sizeof(t_my_list));
}

int	define_data_type(char **data)
{
	if (ft_strcmp(data[0], "A") == 0)
		return (AMBIENT);
	if (ft_strcmp(data[0], "C") == 0)
		return (CAMERA);
	if (ft_strcmp(data[0], "L") == 0)
		return (LIGHT);
	if (ft_strcmp(data[0], "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(data[0], "pl") == 0)
		return (PLANE);
	if (ft_strcmp(data[0], "cy") == 0)
		return (CYLINDER);
	if (ft_strcmp(data[0], "#") == 0)
		return (COMMENT);
	return (ERROR);
}

int	scene_setting(int data_type, char **data, t_scene *scene)
{
	if (data_type == AMBIENT && set_ambient(data, scene))
		return (-1);
	if (data_type == CAMERA && set_camera(data, scene))
		return (-1);
	if (data_type == LIGHT && set_light(data, scene))
		return (-1);
	if (data_type == SPHERE && alloc_sphere(data, scene))
		return (-1);
	if (data_type == PLANE && alloc_plane(data, scene))
		return (-1);
	if (data_type == CYLINDER && alloc_cylinder(data, scene))
		return (-1);
	return (0);
}

int	parse_and_alloc_into_struct(char *str, t_scene *scene)
{
	char	**data;
	int		data_type;

	data = ft_split_charset(str, " 	");
	if (!data)
		return (-1);
	data_type = define_data_type(data);
	if (data_type == ERROR || scene_setting(data_type, data, scene))
	{
		ft_free_2d_array(data);
		return (-1);
	}
	ft_free_2d_array(data);
	return (0);
}

int	read_file_init_struct(char *file, t_scene *scene)
{
	char		*str;
	const int	fd = open(file, O_RDONLY);

	init_scene(scene);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (ft_strcmp(str, "\n") && parse_and_alloc_into_struct(str, scene))
		{
			error_print(SCENE_ERR);
			free(str);
			free_objects(scene->objects);
			return (-1);
		}
		free(str);
	}
	check_scene(scene);
	print_scene(scene);
	return (0);
}
