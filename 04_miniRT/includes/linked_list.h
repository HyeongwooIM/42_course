/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:11:48 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/18 03:13:34 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "rt_struct.h"

t_node	*create_node(void *content, int data_type);
void	list_add_front(t_my_list *list, t_node *new);
void	list_add_back(t_my_list *list, t_node *new);
t_node	*list_pop_front(t_my_list *list);
t_node	*list_pop_back(t_my_list *list);

#endif