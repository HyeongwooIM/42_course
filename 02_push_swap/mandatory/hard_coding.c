/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:24:02 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:18 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_coding(t_stack *stack)
{
	if (stack->a_size == 1)
		return ;
	else if (stack->a_size == 2)
		sort_two(stack);
	else if (stack->a_size == 3)
		sort_three(stack);
	else if (stack->a_size == 4)
		sort_four(stack);
	else if (stack->a_size == 5)
		sort_five(stack);
}
