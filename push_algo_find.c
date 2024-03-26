/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2024/03/27 00:34:47 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



//enters the node which we search the value for  ++ and B
static void	ft_cost_assigner(t_value *node, t_value **a, t_value **b)
{
	t_value	*b_node;
	t_value	*buffer;
	int		i;
	int		a_size;
	int		b_size;

	i = 0;
	buffer = *b;
	// a_size = ft_util_stacksize(*a);
	a_size = 1;
	// b_size = ft_util_stacksize(*b);
	if ((*b) != 0)
	{
		b_node = (*b);
		while ((b_node != 0))
		{
			b_node->s_index = i;
			i++;
			b_node = b_node->next;
		}
		b_size = i;
		b_node = (*b);
		while (b_node->value < node->value && b_node != 0)
		{
			b_node = b_node->next;
		}
		if (b_node == 0)
			b_node = b_node->prev;
		b_node->move_up = b_node->s_index;
		b_node->mover_two = b_size - b_node->s_index;
		node->move_up = node->s_index;
		node->mover_two = a_size - node->s_index;
		if (node->move_up < node->mover_two && b_node->move_up <= node->move_up)
			node->cost = node->move_up;
		else if (node->move_up > node->mover_two && b_node->mover_two <= node->mover_two)
			node->cost = node->mover_two;
		else
			node->cost = b_node->mover_two;
	}
}

void	ft_cost_assigner_macro(t_value **a, t_value **b)
{
	t_value	*nodee;
	t_value	*next_node;

	nodee = *a;
	while (nodee->prev)
		nodee = nodee->prev;
	while (nodee)
	{
		next_node = nodee->next;
		ft_cost_assigner(nodee, a, b);
		nodee = next_node;
	}
	while ((*a)->prev)
		(*a) = (*a)->prev;
}

// static void	ft_cost_assigner(t_value *node, t_value **b)
// {
// 	t_value	*b_node;
// 	int		valueone;
// 	int		cost;

// 	cost = 0;
// 	if ((*b) != 0 && (*b)->next != 0 && (*b)->next->next != 0)
// 	{
// 		b_node = *b;
// 		while (!(b_node->value < node->value) && b_node->next != 0)
// 			b_node = b_node->next;
// 		// while (!(b_node->value < node->value && b_node->s_index == 0
// 		// 		&& ((ft_last(b))->value > node->value
// 		// 			|| b_node->value == ft_biggestvalueinstack(b))))
// 		// 	b_node = b_node->next;
// 		valueone = b_node->value;
// 		if (node->s_index < (ft_list_size(&node) / 2))
// 			cost = node->s_index;
// 		else
// 			cost = node->s_index - (node->s_index % (ft_list_size(&node) / 2));
// 		cost += b_node->s_index;
// 	}
// 	node->cost = cost;
// 	node->s_index = valueone;
// }

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
	ft_cost_assigner_macro(a, b);
	// ft_mover
	if (*b)
	{
		if ((*b)->next)
			ft_subfindmove(a, b);
		ft_clean(b);
	}
}
