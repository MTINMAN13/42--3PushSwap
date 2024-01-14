/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2024/01/14 20:58:36 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//finds the largest value and aligns the stacks in order to move them (only ra!)
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

//add function utilizing the COST aspect of the t_value
//go through each node in the t_value chain, assign cost
void	ft_findmove(t_value **a, t_value **b)
{
	if (*b)
	{
		if ((*b)->next)
			ft_subfindmove(a, b);
		ft_clean(b);
	}
}

