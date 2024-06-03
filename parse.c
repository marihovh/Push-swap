/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 05:05:02 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:17:59 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*space(char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	ret = malloc((len + 2) * sizeof(char));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

int	valid_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' \
					|| str[i] == '+') && !(str[i] == ' '))
			return (0);
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i - 1] != ' ' && i != 0)
				return (0);
			if (str[i + 1] == '-' || str[i + 1] == '+' \
					|| !str[i + 1] || str[i + 1] == ' ')
				return (0);
		}
	}
	return (1);
}

void	parse(t_all *data, char **argv)
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
	if (sorted_arr(data))
		exit(2);
	cpy_array(data);
	quicksort(data->sorted, 0, data->count - 1);
	add_idx(data);
}

void	add_idx(t_all *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= data->count)
	{
		j = -1;
		while (++j <= data->count)
		{
			if (data->unsorted[i] == data->sorted[j])
			{
				data->unsorted[i] = j;
				break ;
			}
		}
	}
}

int	create_array(t_all *data, char *str)
{
	long		i;
	char		**splited;
	long int	num;
	int			len;

	i = 0;
	len = 0;
	data->count = ft_word_cnt(str, ' ');
	data->unsorted = malloc(sizeof(int) * data->count);
	splited = ft_split(str, ' ');
	while (splited[i])
	{
		len = ft_strlen(no_zero(splited[i]));
		num = ft_long_atoi(splited[i]);
		if ((num >= INT_MIN && num <= INT_MAX) && len <= 10)
			data->unsorted[i] = (int)num;
		else
		{
			free_splited(splited);
			return (0);
		}
		i++;
	}
	free_splited(splited);
	return (1);
}
