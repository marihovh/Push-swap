/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 03:28:47 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/16 03:44:26 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **a)
{
	t_node	*tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
}

void	sb(t_node **b)
{
	t_node	*tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
}
