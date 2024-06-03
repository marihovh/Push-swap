/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:28:52 by marihovh          #+#    #+#             */
/*   Updated: 2023/05/19 18:26:33 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include "./check/get_next_line.h"

typedef struct s_all	t_all;
typedef struct s_node	t_node;

struct s_node
{
	int				content;
	int				id;
	struct s_node	*next;
};

struct s_all
{
	int	*unsorted;
	int	*sorted;
	int	count;
	int	step;
};

void		ra(t_node **a);
void		rb(t_node **b);
void		sa(t_node **a);
void		sb(t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
char		*space(char *str);
void		second(t_node **a);
void		init_id(t_node **b);
char		*no_zero(char *str);
int			find_max(t_node **b);
void		error_msg(char *str);
void		swap(int *a, int *b);
int			find_min(t_node **a);
void		add_idx(t_all *data);
int			valid_char(char *str);
void		rev_rotate(t_node **a);
void		cpy_array(t_all *data);
int			sorted_list(t_node *a);
int			dublicate(t_all *data);
int			sorted_arr(t_all *data);
void		tree(int num, t_node **a);
void		ss(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		pa(t_node **a, t_node **b);
void		rr(t_node **a, t_node **b);
void		rrr(t_node **a, t_node **b);
void		free_splited(char **splited);
void		five(t_node **a, t_node **b);
long long	ft_long_atoi(const char *str);
void		printArray(int *arr, int count);
void		parse(t_all *data, char **argv);
int			create_array(t_all *data, char *str);
void		parse_check(t_all *data, char **argv);
void		quicksort(int *arr, int min, int max);
int			quick_help(int *arr, int min, int max);
void		array_cpy(int *dst, int *src, int size);
int			quick_help(int arr[], int min, int max);
void		foo(t_all *data, t_node **a, t_node **b);
void		to_a(t_all *data, t_node **a, t_node **b);
void		but_b(t_all *data, t_node **a, t_node **b);
void		add_index(int *idx, int *sorted, int size);
void		init_stack_a(t_node **stack_a, t_all *data);
void		numeric(t_all *data, t_node **a, t_node **b);
void		butterfly(t_all *data, t_node **a, t_node **b);

#endif
