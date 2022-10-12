/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:24:12 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:36 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revers_rotate_a(t_stack *stack)
{
	if (!stack || stack->a_size < 2)
		return ;
	stack->a_top->prev = stack->a_bottom;
	stack->a_bottom->next = stack->a_top;
	stack->a_top = stack->a_bottom;
	stack->a_bottom = stack->a_bottom->prev;
	stack->a_top->prev = 0;
	stack->a_bottom->next = 0;
}

void	ft_revers_rotate_b(t_stack *stack)
{
	if (!stack || stack->b_size < 2)
		return ;
	stack->b_top->prev = stack->b_bottom;
	stack->b_bottom->next = stack->b_top;
	stack->b_top = stack->b_bottom;
	stack->b_bottom = stack->b_bottom->prev;
	stack->b_top->prev = 0;
	stack->b_bottom->next = 0;
}

void	ft_rra(t_stack *stack)
{
	ft_revers_rotate_a(stack);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack)
{
	ft_revers_rotate_b(stack);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *stack)
{
	ft_revers_rotate_a(stack);
	ft_revers_rotate_b(stack);
	write(1, "rrr\n", 4);
}
