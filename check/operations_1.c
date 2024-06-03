/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 03:27:44 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/16 03:46:47 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	first = NULL;
	last = NULL;
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}

void	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*last;

	tmp = (*a);
	if (!(*a) || !(*a)->next)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*a);
	(*a) = last;
}

void	rrb(t_node **b)
{
	t_node	*tmp;
	t_node	*last;

	tmp = (*b);
	if (!(*b) || !(*b)->next)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = (*b);
	(*b) = last;
}
