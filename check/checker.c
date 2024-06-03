/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 08:01:55 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:22:39 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	implement(char *str, t_node **a, t_node **b)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		sa(a);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		sb(b);
	else if (ft_strncmp("ss\n", str, 3) == 0)
		ss(a, b);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		pa(a, b);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		pb(a, b);
	else if (ft_strncmp("ra\n", str, 3) == 0)
		ra(a);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		rb(b);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rr(a, b);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rra(a);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rrb(b);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	doing(t_node **stack_a, t_node **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (!implement(str, stack_a, stack_b))
			error_msg("Error\n");
		free(str);
		str = get_next_line(0);
	}
	if (sorted_list(*stack_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int args, char *argv[])
{
	t_all	*data;
	t_node	*stack_a;
	t_node	*stack_b;

	data = malloc(sizeof(t_all));
	stack_a = NULL;
	stack_b = NULL;
	if (!data)
		return (0);
	if (args > 1)
	{
		data->count = args;
		parse_check(data, argv);
		init_stack_a(&stack_a, data);
		if (!stack_a)
			return (0);
		doing(&stack_a, &stack_b);
	}
	return (0);
}
