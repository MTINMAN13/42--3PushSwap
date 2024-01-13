/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2023/12/19 00:02:49 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_findmove(t_value **a, t_value **b)
{
	if (*b)
	{
		if ((*b)->next)
			ft_subfindmove(a, b);
		ft_clean(b);
	}
}

void	ft_subfindmove(t_value **a, t_value **b)
{
	t_value	*blast;
	int		biggest_b;
	int		i;

	i = 1;
	biggest_b = ft_biggestvalueinstack(b);
	blast = ft_last(b);
	ft_clean(b);
	if (!((*a)->value > (*b)->value) || !(blast->value < (*a)->value))
	{
		while (!((*b)->value < (*a)->value) && !((*a)->value < blast->value)
			&& i < 10
			&& !(((*a)->value < blast->value) && ((*b)->value > blast->value)))
		{
			if (!((*a)->value > (*b)->value) && biggest_b != (*b)->value)
				ft_moves_ra(a);
			i++;
		}
	}
	ft_clean(a);
	ft_clean(b);
}
