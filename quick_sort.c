/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:01:09 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:19:49 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	quick_help(int arr[], int min, int max)
{
	int	i;
	int	j;
	int	pivot;

	j = min;
	i = (min - 1);
	pivot = arr[max];
	while (j <= max - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[max]);
	return (i + 1);
}

void	quicksort(int arr[], int min, int max)
{
	int	pi;

	if (min < max)
	{
		pi = quick_help(arr, min, max);
		quicksort(arr, min, pi - 1);
		quicksort(arr, pi + 1, max);
	}
}

char	*no_zero(char *str)
{
	while (*str == '0' && *str)
		str++;
	return (str);
}
