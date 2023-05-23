/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:22:32 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/10 12:58:15 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "linked_list.h"
#include "parse.h"
#include "rt_struct.h"

void	print_object(t_node	*node)
{
	if (node->data_type == SPHERE)
		print_sphere(node->content);
	if (node->data_type == PLANE)
		print_plane(node->content);
	if (node->data_type == CYLINDER)
		print_cylinder(node->content);
}

void	print_list(t_my_list *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = list->head;
	while (tmp)
	{
		printf("[object %d]\n", i);
		i++;
		print_object(tmp);
		printf("\n");
		tmp = tmp->next;
	}
}

void	print_scene(t_scene *scene)
{
	print_ambient(&(scene->ambient));
	printf("\n");
	print_camera(&(scene->camera));
	printf("\n");
	print_light(&(scene->light));
	printf("\n");
	print_list(scene->objects);
}
