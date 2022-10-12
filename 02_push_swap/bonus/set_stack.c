/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:50:30 by him               #+#    #+#             */
/*   Updated: 2022/10/06 20:13:17 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_new_node(t_stack *stack, int num)
{
	t_node	*node;	

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit (1);
	node->value = num;
	if (stack->a_size == 0)
		stack->a_top = node;
	else
		stack->a_bottom->next = node;
	node->prev = stack->a_bottom;
	node->next = 0;
	stack->a_bottom = node;
	node->index = 0;
	stack->a_size += 1;
}

void	str_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}

void	ft_set_stack(t_stack *stack, char **av)
{
	int		idx;
	char	**str;
	int		j;

	j = -1;
	idx = 0;
	while (av[++idx])
	{
		str = ft_split(av[idx], ' ');
		if (!str)
			ft_free_exit (stack);
		while (str[++j])
			ft_new_node(stack, ft_atoi(str[j], stack));
		j = -1;
		str_free(str);
	}
	if (stack->a_top == 0)
		ft_free_exit (stack);
}
