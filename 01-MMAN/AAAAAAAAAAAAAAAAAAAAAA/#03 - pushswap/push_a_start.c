/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:35:19 by mman              #+#    #+#             */
/*   Updated: 2024/01/14 17:52:47 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_value **a)
{
	int	stack_size;

	stack_size = ft_util_stacksize(*a);
	if (stack_size <= 3)
		ft_last_three(a);
	else if (stack_size > 3)
		ft_algo_perform(a);
}

void	ft_last_three(t_value **a)
{
	t_value	*crawl;
	int		done;

	done = 0;
	crawl = ft_util_reset_head(a);
	while (!done)
	{
		crawl = ft_util_reset_head(a);
		done = ft_last_three_logic(a, &crawl);
	}
}

int	ft_last_three_logic(t_value **a, t_value **crawl)
{
	int	first;
	int	second;
	int	third;

	first = (*crawl)->value;
	second = (*crawl)->next->value;
	third = (*crawl)->next->next->value;
	if (second < third && third < first)
		ft_moves_ra(a);
	else if (first > second)
		ft_moves_sa(a);
	else if (first < second && third < first)
		ft_moves_rra(a);
	else if (first < second && third < second)
		ft_moves_ra(a);
	*crawl = ft_util_reset_head(a);
	return (ft_checksorted(*a));
}

void	ft_algo_perform(t_value **a)
{
	t_value	*b;
	int		size;

	b = NULL;
	size = ft_util_stacksize(*a);
	if (size > 3)
		ft_algo_b(a, &b);
	ft_algo_wrap(a, &b);
}
