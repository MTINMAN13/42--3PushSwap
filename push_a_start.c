/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:35:19 by mman              #+#    #+#             */
/*   Updated: 2023/12/11 20:35:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_value	**a)
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
	int		first;
	int		second;
	int		third;
	t_value	*crawl;

	crawl = ft_util_reset_head(a);
	first = crawl->value;
	second = crawl->next->value;
	third = crawl->next->next->value;
	int done = 0;
	while (done != 1)
	{
		crawl = ft_util_reset_head(a);
		first = crawl->value;
		second = crawl->next->value;
		third = crawl->next->next->value;
		if (first > second)
		{
			ft_moves_sa(a);
		}
		else if (first < second && third < first)
		{
			ft_pntf("trigger");
			ft_moves_rra(a);
		}
		else if (first < second && second < third)
			ft_pntf("loopy");
	}
}

// 18 46 32

void	ft_algo_perform(t_value **a)
{
	if (a)
		ft_pntf("performing");
	else
		ft_pntf("error");
}
