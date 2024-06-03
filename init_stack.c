/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:27:10 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/15 16:51:54 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	init_stack_a(t_node **stack_a, t_all *data)
{
	int	i;

	i = -1;
	while (++i < data->count)
	{
		(*stack_a) = ft_new(data->unsorted[i]);
		stack_a = &(*stack_a)->next;
	}
}
