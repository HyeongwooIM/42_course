/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:24:21 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/08 20:21:49 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "linked_list.h"

t_node	*create_node(void *content, int data_type)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->data_type = data_type;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	list_add_front(t_my_list *list, t_node *new)
{
	if (!list || !new)
		return ;
	if (!list->head)
	{
		list->head = new;
		list->tail = NULL;
		list->len += 1;
		return ;
	}
	if (list->head->next == NULL)
		list->tail = list->head;
	list->head->prev = new;
	new->next = list->head;
	new->prev = NULL;
	list->head = new;
	list->len += 1;
}

void	list_add_back(t_my_list *list, t_node *new)
{
	if (!list || !new)
		return ;
	if (!list->head)
	{
		list->head = new;
		list->tail = NULL;
		list->len += 1;
		return ;
	}
	if (list->tail == NULL)
	{
		list->tail = new;
		new->prev = list->head;
		list->head->next = new;
		list->len += 1;
		return ;
	}
	list->tail->next = new;
	new->prev = list->tail;
	list->tail = new;
	list->len += 1;
}

t_node	*list_pop_front(t_my_list *list)
{
	t_node	*next;
	t_node	*head;

	if (!list || !list->head)
		return (NULL);
	head = list->head;
	if (head->next)
	{
		next = head->next;
		next->prev = NULL;
	}
	list->head = head->next;
	head->next = NULL;
	head->prev = NULL;
	list->len -= 1;
	return (head);
}

t_node	*list_pop_back(t_my_list *list)
{
	t_node	*node;

	if (!list || !list->tail)
		return (NULL);
	node = list->tail;
	if (node)
		node->prev->next = NULL;
	else
		node = list->head;
	list->tail = node->prev;
	node->next = NULL;
	node->prev = NULL;
	list->len -= 1;
	return (node);
}
