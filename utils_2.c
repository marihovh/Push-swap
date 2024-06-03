/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:58:45 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:20:40 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_array(t_all *data)
{
	int	i;

	i = -1;
	data->sorted = malloc(sizeof(int) * data->count);
	while (++i < data->count)
		data->sorted[i] = data->unsorted[i];
}

int	sorted_arr(t_all *data)
{
	int	i;

	i = -1;
	while (++i < data->count - 1)
		if (data->unsorted[i] > data->unsorted[i + 1])
			return (0);
	return (1);
}

void	free_splited(char **splited)
{
	int	i;

	i = -1;
	while (splited && splited[++i])
	{
		free(splited[i]);
		splited[i] = NULL;
	}
	free(splited);
}
