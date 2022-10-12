/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:32:54 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:32 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_check(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack->a_top;
	while (temp)
	{
		if (i == temp->index)
			temp = temp->next;
		else
			break ;
		i++;
	}
	if (!temp)
		exit (0);
}
