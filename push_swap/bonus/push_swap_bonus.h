/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:23:16 by him               #+#    #+#             */
/*   Updated: 2022/10/06 20:17:38 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	int		a_size;
	int		b_size;
	t_node	*a_top;
	t_node	*a_bottom;
	t_node	*b_bottom;
	t_node	*b_top;
}t_stack;

//ft_atoi.c
int		ft_atoi(const char *str, t_stack *stack);

//ft_calloc.c
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

//ft_check_num.c
void	check_num(t_stack *stack);

//ft_free_exit.c
void	ft_node_free(t_node *node);
void	ft_free_exit(t_stack *stack);
void	ft_exit(t_stack *stack);

//ft_indexing.c
void	ft_indexing(t_stack *stack);

//ft_new_push.c
void	ft_new_node(t_stack *stack, int num);

//ft_push.c
void	ft_a_change(t_stack *stack);
void	ft_b_change(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);

//ft_revers_rotate.c
void	ft_revers_rotate_a(t_stack *stack);
void	ft_revers_rotate_b(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);

//ft_rotate.c
void	ft_rotate_a(t_stack *stack);
void	ft_rotate_b(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);

//ft_sort_check.c
void	ft_sort_check(t_stack *stack);

//ft_split.c
int		check_word(char *s, char c);
char	**free_all(char **arr, int i);
int		world_len(char *s, int c);
char	**ft_split(char const *s, char c);

//ft_strlen.c
size_t	ft_strlen(const char *s);

//ft_subftr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);

//ft_swap.c
void	ft_swap_a(t_stack *stack);
void	ft_swap_b(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);

//get_next_line_utils.c
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str, char *buff);

//get_next_line.c
char	*ft_get_line(char *str);
char	*ft_backup_str(char *str);
char	*ft_read_to_left_str(int fd, char *str);
char	*get_next_line(int fd);

//push_swap_bonus.c
void	ft_new_stack(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);
void	sort_function(t_stack *stack, char *input);
void	get_param_sort(t_stack *stack);
int		main(int ac, char **av);

//set_stack.c
void	ft_new_node(t_stack *stack, int num);
void	str_free(char **str);
void	ft_set_stack(t_stack *stack, char **av);

//stack_sort.c
void	stack_a_to_b(t_stack *stack, int offset);
void	b_to_a(t_stack *stack);
void	stack_b_to_a(t_stack *stack);
void	stack_sort(t_stack *stack);

#endif