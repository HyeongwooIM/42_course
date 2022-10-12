/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:18:53 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:43 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_stack *stack)
{
	long	min;
	int		i;
	int		j;
	long	prev_min;
	t_node	*temp;

	i = -1;
	prev_min = -2147483649;
	while (++i < stack->a_size)
	{
		min = 2147483648;
		temp = stack->a_top;
		j = -1;
		while (++j < stack->a_size)
		{
			if (temp->value < min && temp->value > prev_min)
			{
				min = temp->value;
				temp->index = i;
			}
			temp = temp->next;
		}
		prev_min = min;
	}
}
