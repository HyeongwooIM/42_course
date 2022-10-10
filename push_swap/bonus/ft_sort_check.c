/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:32:54 by him               #+#    #+#             */
/*   Updated: 2022/10/06 17:52:42 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sort_check(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = stack->a_top;
	while (temp->next)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			break ;
		i++;
	}
	if (!temp->next)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}
