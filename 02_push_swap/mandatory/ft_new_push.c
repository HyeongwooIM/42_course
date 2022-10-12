/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:53:41 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:41 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_node(t_stack *stack, int num)
{
	t_node	*node;	

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit (1);
	node->value = num;
	if (stack->a_size == 0)
		stack->a_top = node;
	else
		stack->a_bottom->next = node;
	node->prev = stack->a_bottom;
	node->next = 0;
	stack->a_bottom = node;
	node->index = 0;
	stack->a_size += 1;
}
