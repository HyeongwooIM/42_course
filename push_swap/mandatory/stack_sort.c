/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:07:19 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:09 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_to_b(t_stack *stack, int offset)
{
	t_node	*a_top;
	int		i;
	int		num_num;

	num_num = stack->a_size;
	i = 0;
	while (stack->a_size)
	{
		a_top = stack->a_top;
		if (a_top->index <= i)
		{
			ft_pb(stack);
			i++;
		}
		else if (i < a_top->index && a_top->index <= i + offset)
		{
			ft_pb(stack);
			ft_rb(stack);
			i++;
		}
		else
			ft_ra(stack);
	}
}

void	b_to_a(t_stack *stack)
{
	int		i;
	t_node	*temp;
	int		b_num;

	i = 0;
	b_num = stack->b_size;
	temp = stack->b_top;
	while (temp->index != stack->b_size - 1)
	{
		i++;
		temp = temp->next;
	}
	while (stack->b_top->index < stack->b_size - 1)
	{
		if (i < stack->b_size / 2)
			ft_rb(stack);
		else
			ft_rrb(stack);
	}
}

void	stack_b_to_a(t_stack *stack)
{
	while (stack->b_size > 0)
	{
		b_to_a(stack);
		ft_pa(stack);
	}
}

void	stack_sort(t_stack *stack)
{
	int		offset;
	int		i;

	i = stack->a_size;
	offset = 0.000000053 * i * i + 0.03 * i + 14.5;
	stack_a_to_b(stack, offset);
	stack_b_to_a(stack);
}
