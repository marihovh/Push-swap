/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:28:41 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:20:25 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_long_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	num;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		num = (num * 10) + (str[i++] - 48);
	return (num * minus);
}

void	error_msg(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	exit (1);
}

int	sorted_list(t_node *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	dublicate(t_all *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->count)
	{
		j = 0;
		while (j < i)
		{
			if (data->unsorted[i] == data->unsorted[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
