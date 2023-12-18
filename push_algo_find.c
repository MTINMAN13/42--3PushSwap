/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:37:35 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_findmove(t_value **a, t_value **b)
{
	if ((*b))
	{
		if ((*b)->next)
		{
			ft_subfindmove(a, b); // calculate the optimal distance for a move
			ft_pntf("finds optimal pair to make sure b is descending %i, %i", (*a)->value, (*b));
		}
		ft_clean(b);
	}
}

void	ft_subfindmove(t_value **a, t_value **b)
{
	t_value	*blast;
	int		bigestb;
	// int		bigesta;

	bigestb = ft_biggestvalueinstack(b);
	// bigesta = ft_biggestvalueinstack(a);
	blast = ft_last(b);
	ft_clean(b);
	int i = 1;
	if (!((*a)->value > (*b)->value) || !(blast->value < (*a)->value))
	{ // todo OPTIMIZE THE PICKS
		while (!((*b)->value < (*a)->value) && !((*a)->value < blast->value) && i < 10
				&& !(((*a)->value < blast->value) && ((*b)->value > blast->value)))
		{
			if (!((*a)->value > (*b)->value) && bigestb != (*b)->value)
				ft_moves_ra(a);
			i++;
		}
	}
	ft_clean(a);
	ft_clean(b);
}
