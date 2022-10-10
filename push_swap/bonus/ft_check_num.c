/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:43 by him               #+#    #+#             */
/*   Updated: 2022/10/06 17:36:04 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_num(t_stack *stack)
{
	t_node	*temp;
	t_node	*num;
	int		i;
	int		j;

	i = -1;
	temp = stack->a_top;
	while (++i < stack->a_size)
	{
		j = i;
		num = temp->next;
		while (++j < stack->a_size)
		{
			if (num->value == temp->value)
				ft_free_exit (stack);
			num = num->next;
		}
		temp = temp->next;
	}
}
