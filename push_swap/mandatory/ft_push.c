/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:23 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:37 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_change(t_stack *stack)
{
		stack->a_top = stack->b_top;
		stack->a_bottom = stack->b_top;
}

void	ft_b_change(t_stack *stack)
{
		stack->b_top = stack->a_top;
		stack->b_bottom = stack->a_top;
}

void	ft_pa(t_stack *stack)
{
	t_node	*temp;

	if (!stack->b_top)
		return ;
	temp = stack->b_top->next;
	if (stack->a_top == 0)
	{
		ft_a_change(stack);
		stack->a_bottom->next = 0;
		stack->a_top->prev = 0;
	}
	else
	{
		stack->a_top->prev = stack->b_top;
		stack->b_top->next = stack->a_top;
		stack->a_top = stack->b_top;
	}
	stack->b_top = temp;
	if (temp)
		stack->b_top->prev = 0;
	else
		stack->b_bottom = 0;
	write(1, "pa\n", 3);
	stack->a_size += 1;
	stack->b_size -= 1;
}

void	ft_pb(t_stack *stack)
{
	t_node	*temp;

	if (!stack->a_top)
		return ;
	temp = stack->a_top->next;
	if (stack->b_top == 0)
	{
		ft_b_change(stack);
		stack->b_bottom->next = 0;
		stack->b_top->prev = 0;
	}
	else
	{
		stack->b_top->prev = stack->a_top;
		stack->a_top->next = stack->b_top;
		stack->b_top = stack->a_top;
	}
	stack->a_top = temp;
	if (temp)
		stack->a_top->prev = 0;
	else
		stack->a_bottom = 0;
	write(1, "pb\n", 3);
	stack->a_size -= 1;
	stack->b_size += 1;
}
