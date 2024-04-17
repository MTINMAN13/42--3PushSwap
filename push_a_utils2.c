/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 18:43:14 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean(t_value **a)
{
	while ((*a)->prev)
		(*a) = (*a)->prev;
}

int	ft_biggestvalueinstack(t_value **a)
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
	ft_clean(a);
	return (holder);
}

int	ft_smallestvalueinstack(t_value **a)
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
	return (holder);
}

t_value	*ft_last(t_value **x)
{
	t_value	*z;

	z = *x;
	while (z->next != 0)
		z = z->next;
	return (z);
}

int	ft_stack_size(t_value **entry_node)
{
	int		counter;
	t_value	*buffer;

	counter = 0;
	buffer = *entry_node;
	ft_clean(&buffer);
	while (buffer->next != 0)
	{
		buffer = buffer->next;
		counter++;
	}
	return (counter);
}
