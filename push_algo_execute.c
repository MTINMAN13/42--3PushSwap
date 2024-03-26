/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:20 by mman              #+#    #+#             */
/*   Updated: 2024/03/26 20:53:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_b(t_value **a, t_value **b)
{
	t_value	*movin;
	int		stacksize;

	movin = *a;
	stacksize = ft_util_stacksize(*a);
	while (stacksize > 3)
	{
		ft_findmove(a, b);
		ft_moves_pa(&movin, b);
		stacksize--;
	}
	(*a) = movin;
	ft_clean(a);
}

void	ft_algo_wrap(t_value **a, t_value **b)
{
	ft_last_three(a);
	ft_check_descending(b);
	ft_back_to_a(a, b);
}

//Needs polish
void	ft_back_to_a(t_value **a, t_value **b)
{
	while ((*b) != 0)
	{
		ft_sub_aligner(a, b);
		ft_moves_pb(a, b);
	}
	if (!ft_checksorted(*a))
	{
		while (!ft_checksorted(*a))
			ft_moves_ra(a);
		while (!ft_checksorted(*a))
			ft_moves_rra(a);
	}
}

void	ft_sub_aligner(t_value **a, t_value **b)
{
	int	a_last;
	int	small;
	int	big;

	big = ft_biggestvalueinstack(a);
	small = ft_smallestvalueinstack(a);
	a_last = ft_last(a)->value;
	while (((*b)->value < small && !(a_last == big))
		|| ((*b)->value > big && !((*a)->value == small))
		|| (((*b)->value > small && (*b)->value < big)
			&& !((*b)->value < (*a)->value && (*b)->value > a_last)))
	{
		ft_moves_ra(a);
		ft_clean(a);
		a_last = ft_last(a)->value;
	}
	ft_last_b(a, b);
	ft_clean(a);
	ft_clean(b);
}

void	ft_last_b(t_value **a, t_value **b)
{
	int	a_last;
	int	i;
	int	small;
	int	big;

	small = ft_smallestvalueinstack(a);
	big = ft_biggestvalueinstack(a);
	i = 0;
	a_last = ft_last(a)->value;
	ft_clean(b);
	ft_clean(a);
	if ((*b)->next == 0)
	{
		while (i < 13
			&& (((*b)->value < small && !(a_last == big))
				|| ((*b)->value > big && !((*a)->value == small))
				|| (((*b)->value > small && (*b)->value < big)
					&& !((*b)->value < (*a)->value && (*b)->value > a_last))))
		{
			ft_moves_rra(a);
			ft_clean(a);
			a_last = ft_last(a)->value;
			i++;
		}
	}
}
