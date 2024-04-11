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
int	ft_util_b_value_cheapest(t_value **stack, int searched_index)
{
	t_value	*first;
	int		current_i;

	current_i = INT_MIN;
	if (!stack || searched_index < -1)
		ft_error();
	first = (*stack);
	ft_clean(&first);
	while (first->value != searched_index && first->next)
	{
		first = first->next;
	}
	current_i = first->b_value;
	return (current_i);
}

// up = 1;  down = 0 (reverse);
int	ft_direction(t_value **a)
{
	t_value	*buffer;
	int		value;
	int		up;
	int		down;

	value = ft_lowest_value(a);
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

void	ft_subsubfindmove(t_value **a, t_value **b, int x, int y)
{
	while ((*a)->cost != x)
	{
		while ((*b)->value != y)
			ft_moves_rrr(a, b);
		ft_moves_rra(a);
	}
}

void	ft_subcostassigner(t_value *node, t_value *b_node
	, int a_size, t_value **b)
{
	int	b_size;

	b_size = ft_stack_size(b);
	while ((b_node->value < node->value && b_node->next)
		|| b_node->next != 0)
		b_node = b_node->next;
	if (b_node->value > node->value)
	{
		while (b_node->value != ft_smallestvalueinstack(b))
			b_node = b_node->prev;
	}
	b_node->move_up = b_node->s_index;
	b_node->mover_two = b_size - b_node->s_index;
	node->b_value = b_node->value;
	node->move_up = node->s_index;
	node->mover_two = a_size - node->s_index;
	if (node->move_up < node->mover_two && b_node->move_up <= node->move_up)
		node->cost = node->move_up;
	else if (node->move_up > node->mover_two
		&& b_node->mover_two <= node->mover_two)
		node->cost = node->mover_two;
	else
		node->cost = b_node->mover_two;
}
