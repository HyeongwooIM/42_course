/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:29:37 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:17 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->a_top->value > stack->a_top->next->value)
		ft_sa(stack);
	else
		return ;
}

void	sort_three(t_stack *stack)
{
	if (stack->a_bottom->index == 2)
		sort_two(stack);
	else
	{
		if (stack->a_top->next->index == 2)
			ft_rra(stack);
		else
			ft_ra(stack);
		sort_two(stack);
	}
}

void	sort_four(t_stack *stack)
{
	while (stack->a_top->index != 0)
		ft_ra(stack);
	ft_pb(stack);
	ft_indexing(stack);
	sort_three(stack);
	ft_pa(stack);
}

void	ft_search_rotate(t_stack *stack)
{
	if (stack->a_bottom->index < 2 || stack->a_bottom->prev->index < 2)
		ft_rra(stack);
	else
		ft_ra(stack);
}

void	sort_five(t_stack *stack)
{
	int	i;

	i = 0;
	while (1)
	{
		if (stack->a_top->index < 2)
		{
			ft_pb(stack);
			i++;
		}
		if (i == 2)
			break ;
		ft_search_rotate(stack);
	}
	if (stack->b_top->index < stack->b_bottom->index)
		ft_rb(stack);
	ft_indexing(stack);
	sort_three(stack);
	ft_pa(stack);
	ft_pa(stack);
}
