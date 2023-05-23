/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:59:19 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/10 22:52:06 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rt_struct.h"

void	free_objects(t_objects *objects)
{
	t_node	*cur;
	t_node	*tmp;

	cur = objects->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->content);
		free(cur);
		cur = tmp;
	}
	free(objects);
}
