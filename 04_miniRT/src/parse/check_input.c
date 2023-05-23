/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:09:42 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 13:02:07 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_error.h"
#include "libft.h"
#include "parse.h"
#include "rt_struct.h"

static int	is_valid_argc(int argc)
{
	if (argc != 2)
		return (-1);
	return (0);
}

static int	is_valid_extension(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
			i++;
	while (i-- >= 1)
	{
		if (str[i] == '.' && str[i - 1] == '/')
			return (-1);
		if (str[i] == '.')
			break ;
	}
	if (ft_strcmp(".rt", &str[i]) != 0)
		return (-1);
	return (0);
}

int	is_valid_input(int argc, char **argv)
{
	if (is_valid_argc(argc))
		return (error_print(AC_ERR));
	if (is_valid_extension(argv[1]))
		return (error_print(AR_ERR));
	return (0);
}

void	check_scene(t_scene *scene)
{
	if (!scene->dup_check.x || !scene->dup_check.y
		|| !scene->dup_check.z)
	{
		error_print(SCENE_ERR);
		free_objects(scene->objects);
		exit(ERROR);
	}
}
