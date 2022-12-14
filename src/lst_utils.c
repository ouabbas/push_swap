/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:20:24 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/21 13:48:57 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!new)
		return;
	if (*lst)
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else if (*lst == NULL)
		*lst = new;
}

t_list *ft_lstnew(int content)
{
	t_list *node;

	node = calloc(sizeof(t_list), 1);
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int *tableau(t_list **lst)
{
	int i;
	int *tab;
	t_list *temp;

	temp = *lst;
	i = 0;
	tab = calloc(sizeof(int), (ft_lstsize(*lst)));
	if (!tab)
		return (0);
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (tab);
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}
