/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 20:06:28 by mman             ###   ########.fr       */
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
	a_size = ft_stack_size(a);
	if ((*b) != 0 && (*b)->next && (*b)->next->next)
	{
		buffer = *b;
		b_node = (*b);
		ft_clean(&b_node);
		while ((b_node->next))
		{
			b_node->s_index = i;
			i++;
			b_node = b_node->next;
		}
		b_node->s_index = i;
		b_size = i;
		ft_clean(&b_node);
		ft_subcostassigner(node, b_node, a_size, b);
	}
}

void	ft_cost_assigner_macro(t_value **a, t_value **b)
{
	t_value	*nodee;
	t_value	*next_node;

	nodee = *a;
	while (nodee->prev)
		nodee = nodee->prev;
	while (nodee->next != 0)
	{
		next_node = nodee->next;
		ft_cost_assigner(nodee, a, b);
		nodee = next_node;
	}
	ft_cost_assigner(nodee, a, b);
	while ((*a)->prev)
		(*a) = (*a)->prev;
}

int	ft_lowest_value(t_value **a)
{
	t_value	*buffer;
	int		i;

	buffer = *a;
	i = buffer->cost;
	while (buffer->next != 0)
	{
		if (buffer->cost < i)
			i = buffer->cost;
		buffer = buffer->next;
	}
	return (i);
}

//a's have some value(cost) -- i want to find the
void	ft_subfindmove(t_value **a, t_value **b)
{
	int	cheapest;
	int	direction;
	int	b_head;

	cheapest = ft_lowest_value(a);
	b_head = ft_util_b_value_cheapest(a, cheapest);
	direction = ft_direction(a);
	{
		if (direction)
		{
			while ((*a)->value != cheapest)
			{
				while ((*b)->value != b_head)
					ft_moves_rr(a, b);
				ft_moves_ra(a);
			}
		}
		else
			ft_subsubfindmove(a, b, cheapest, b_head);
	}
}

//add function utilizing the COST aspect of the t_value
//go through each node in the t_value chain, assign cost
void	ft_findmove(t_value **a, t_value **b)
{
	ft_cost_assigner_macro(a, b);
	if (*b && (*b)->next && (*b)->next->next)
	{
		if ((*b)->next != 0)
			ft_subfindmove(a, b);
		ft_clean(b);
	}
}
