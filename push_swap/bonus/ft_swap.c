/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:17:59 by him               #+#    #+#             */
/*   Updated: 2022/10/06 17:40:17 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_a(t_stack *stack)
{
	int	temp;

	if (!stack || stack->a_size < 2)
		return ;
	temp = stack->a_top->value;
	stack->a_top->value = stack->a_top->next->value;
	stack->a_top->next->value = temp;
}

void	ft_swap_b(t_stack *stack)
{
	int	temp;

	if (!stack || stack->b_size < 2)
		return ;
	temp = stack->b_top->value;
	stack->b_top->value = stack->b_top->next->value;
	stack->b_top->next->value = temp;
}

void	ft_sa(t_stack *stack)
{
	ft_swap_a(stack);
}

void	ft_sb(t_stack *stack)
{
	ft_swap_b(stack);
}

void	ft_ss(t_stack *stack)
{
	ft_swap_a(stack);
	ft_swap_b(stack);
}
