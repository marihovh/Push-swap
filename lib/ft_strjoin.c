/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:21:06 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 17:39:34 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *stat, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	c;

	if (!stat)
	{
		stat = (char *)malloc(sizeof(char));
		stat[0] = '\0';
	}
	if (!stat || !buffer)
		return (NULL);
	i = -1;
	c = -1;
	join = (char *)malloc(sizeof(char)
			* (ft_strlen(stat) + ft_strlen(buffer) + 2));
	if (!join)
		return (NULL);
	while (stat[++i] != '\0')
		join[i] = stat[i];
	while (buffer[++c])
		join[i++] = buffer[c];
	join[i] = ' ';
	join[i + 1] = '\0';
	free(stat);
	return (join);
}
