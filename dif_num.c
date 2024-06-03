/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dif_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:01:04 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/18 16:32:05 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tree(int num, t_node **a)
{
	if ((*a)->content == num - 3)
	{
		rra(a);
		sa(a);
		return ;
	}
	if ((*a)->content == num - 2)
	{
		if ((*a)->next->content == num - 3)
			sa(a);
		else
			rra(a);
		return ;
	}
	if ((*a)->content == num - 1)
	{
		if ((*a)->next->content == num - 3)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
		return ;
	}
}

void	four(int num, t_node **a, t_node **b)
{
	int	min;

	init_id(a);
	min = find_min(a);
	while ((*a)->id != min)
		rra(a);
	if (sorted_list(*a) != 1)
	{
		pb(a, b);
		tree(num, a);
		pa(a, b);
	}
}

void	five(t_node **a, t_node **b)
{
	int	i;
	int	min;

	i = 0;
	init_id(a);
	min = find_min(a);
	if (min < 3)
	{
		while (min-- > 0)
			ra(a);
	}
	else
	{
		i = 5 - min;
		while (i-- > 0)
			rra(a);
	}
	if (sorted_list(*a) != 1)
	{
		pb(a, b);
		four(5, a, b);
		pa(a, b);
	}
}

int	find_min(t_node **a)
{
	t_node	*min;
	t_node	*tmp;

	tmp = *a;
	min = (*a);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->content <= min->content)
			min = tmp;
	}
	return (min->id);
}

void	numeric(t_all *data, t_node **a, t_node **b)
{
	if (data->count == 2)
		sa(a);
	else if (data->count == 3)
		tree(data->count, a);
	else if (data->count == 4)
		four(4, a, b);
	else if (data->count == 5)
		five(a, b);
}
