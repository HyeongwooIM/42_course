/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:37:07 by him               #+#    #+#             */
/*   Updated: 2022/10/06 21:04:48 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_new_stack(t_stack *stack)
{
	stack->a_top = 0;
	stack->a_bottom = 0;
	stack->a_size = 0;
	stack->b_top = 0;
	stack->b_bottom = 0;
	stack->b_size = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	sort_function(t_stack *stack, char *input)
{
	if (!ft_strcmp(input, "sa\n"))
		ft_sa(stack);
	else if (!ft_strcmp(input, "sb\n"))
		ft_sb(stack);
	else if (!ft_strcmp(input, "ss\n"))
		ft_ss(stack);
	else if (!ft_strcmp(input, "pa\n"))
		ft_pa(stack);
	else if (!ft_strcmp(input, "pb\n"))
		ft_pb(stack);
	else if (!ft_strcmp(input, "ra\n"))
		ft_ra(stack);
	else if (!ft_strcmp(input, "rb\n"))
		ft_rb(stack);
	else if (!ft_strcmp(input, "rr\n"))
		ft_rr(stack);
	else if (!ft_strcmp(input, "rra\n"))
		ft_rra(stack);
	else if (!ft_strcmp(input, "rrb\n"))
		ft_rrb(stack);
	else if (!ft_strcmp(input, "rrr\n"))
		ft_rrr(stack);
	else
		ft_free_exit(stack);
}

void	get_param_sort(t_stack *stack)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (input == 0)
			break ;
		sort_function(stack, input);
		free(input);
	}
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
	get_param_sort(stack);
	ft_sort_check(stack);
	ft_exit (stack);
	sleep(100000);
}
