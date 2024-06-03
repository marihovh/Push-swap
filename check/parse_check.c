/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:20:42 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:21:12 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_check(t_all *data, char **argv)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (++i < data->count)
	{
		argv[i] = space(argv[i]);
		str = ft_strjoin(str, argv[i]);
	}
	if (!valid_char(str) || !create_array(data, str) || !dublicate(data))
	{
		free(str);
		error_msg("Error\n");
	}
	free(str);
	cpy_array(data);
	quicksort(data->sorted, 0, data->count - 1);
	add_idx(data);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}
