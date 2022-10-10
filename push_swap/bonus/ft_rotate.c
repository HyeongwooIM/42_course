/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:47:42 by him               #+#    #+#             */
/*   Updated: 2022/10/06 17:39:41 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate_a(t_stack *stack)
{
	if (!stack || stack->a_size < 2)
		return ;
	stack->a_top->prev = stack->a_bottom;
	stack->a_bottom->next = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_bottom = stack->a_top->prev;
	stack->a_top->prev = 0;
	stack->a_bottom->next = 0;
}

void	ft_rotate_b(t_stack *stack)
{
	if (!stack || stack->b_size < 2)
		return ;
	stack->b_top->prev = stack->b_bottom;
	stack->b_bottom->next = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_bottom = stack->b_top->prev;
	stack->b_top->prev = 0;
	stack->b_bottom->next = 0;
}

void	ft_ra(t_stack *stack)
{
	ft_rotate_a(stack);
}

void	ft_rb(t_stack *stack)
{
	ft_rotate_b(stack);
}

void	ft_rr(t_stack *stack)
{
	ft_rotate_a(stack);
	ft_rotate_b(stack);
}
