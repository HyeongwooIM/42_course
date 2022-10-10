/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:43:40 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:15 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_stack(t_stack *stack)
{
	stack->a_top = 0;
	stack->a_bottom = 0;
	stack->a_size = 0;
	stack->b_top = 0;
	stack->b_bottom = 0;
	stack->b_size = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2 || !av[1][0])
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	ft_new_stack(stack);
	ft_set_stack(stack, av);
	check_num(stack);
	ft_indexing(stack);
	ft_sort_check(stack);
	if (stack->a_size > 5)
		stack_sort(stack);
	else
		hard_coding(stack);
	ft_exit (stack);
}
// void print_stack(t_stack *stack)
// {
// 	// stack a
// 	t_node *a;
// 	a = stack->a_top;
// 	printf("-- a --\n");
// 	for (int i = 0; i < stack->a_size; i++)
// 	{
// 		printf("%d - index %d \n", a->value, a->index);
// 		a = a->next;
// 	}

// 	// stack b
// 	printf("\n\n-- b --\n");
// 	t_node *b;
// 	b = stack->b_top;
// 	for (int i = 0; i < stack->b_size; i++)
// 	{
// 		printf("%d\n", b->value);
// 		b = b->next;
// 	}
// 	printf("\n a : %d, b : %d\n ", stack->a_size, stack->b_size);
// 	printf("\n-------------------------\n");
// }
