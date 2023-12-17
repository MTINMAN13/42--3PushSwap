/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:34:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_value **a)
{
	while ((*a)->prev)
		(*a) = (*a)->prev;
}

int		ft_biggestvalueinstack(t_value **a)
{
	int		holder;
	t_value	*h;

	holder = INT_MIN;
	h = *a;
	if ((*a) != 0)
	{
		while (*a)
		{
			if (holder < (*a)->value)
				holder = (*a)->value;
			(*a) = (*a)->next;
		}
	}
	(*a) = h;
	// ft_pntf("i think biggest number in stack is %i", holder);
	// fullstack(*a);
	return (holder);
}

int		ft_smallestvalueinstack(t_value **a)
{
	int		holder;
	t_value	*h;

	holder = INT_MAX;
	h = *a;
	if ((*a) != 0)
	{
		while (*a)
		{
			if (holder > (*a)->value)
				holder = (*a)->value;
			(*a) = (*a)->next;
		}
	}
	(*a) = h;
	// ft_pntf("i think biggest number in stack is %i", holder);
	// fullstack(*a);
	return (holder);
}
