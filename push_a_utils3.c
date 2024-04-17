/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:14:54 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 20:09:13 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//takes in stack, and value representing the current cheapest-to-move item
// returns the b_value of that field
//it must be closest smaller than searched index
// go in the stack and find closest smaller value
int	ft_find_closest_smaller(t_value **stack, int searched_index)
{
	t_value	*first;
	int		current_smallest;

	current_smallest = INT_MIN;
	if (!stack || searched_index < -1)
		ft_error();
	first = (*stack);
	while (first->next != NULL)
	{
		if (first->value > current_smallest && first->value < searched_index)
			current_smallest = first->value;
		first = first->next;
	}
	if (current_smallest == INT_MIN)
		current_smallest = ft_biggestvalueinstack(stack);
	// printf("current closest smallest to %i is %i\n", searched_index, current_smallest);
	return (current_smallest);
}

// up = 1;  down = 0 (reverse);
int	ft_direction(t_value **a)
{
	t_value	*buffer;
	int		value;
	int		up;
	int		down;

	value = ft_lowest_cost(a)->value;
	buffer = *a;
	ft_clean(&buffer);
	up = buffer->move_up;
	down = buffer->mover_two;
	while (buffer->next != 0 && buffer->value != value)
	{
		buffer = buffer->next;
	}
	up = buffer->move_up;
	down = buffer->mover_two;
	if (up >= down)
		return (0);
	else
		return (1);
	return (-1);
}

void	ft_subsubfindmove(t_value **a, t_value **b, int moving_a_value, int moving_b_value)
{
	while ((*a)->value != moving_a_value)
	{
		while ((*b)->value != moving_b_value)
			// ft_moves_rrr(a, b);
		ft_moves_rra(a);
	}
}