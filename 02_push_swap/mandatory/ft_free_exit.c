/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:10:50 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:44 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_free(t_node *node)
{
	t_node	*temp;

	temp = node;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	ft_free_exit(t_stack *stack)
{
	ft_node_free(stack->a_top);
	ft_node_free(stack->b_top);
	write(1, "error\n", 6);
	exit (0);
}

void	ft_exit(t_stack *stack)
{
	ft_node_free(stack->a_top);
	ft_node_free(stack->b_top);
	exit (0);
}
