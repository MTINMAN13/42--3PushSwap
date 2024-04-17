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
void ft_cost_assigner(t_value *node, t_value **a, t_value **b)
{
    t_value *b_node;
    int     i;
    int     a_size;

    i = 0;
    a_size = ft_stack_size(a);
    if ((*b) && (*b)->next)
    {
        b_node = (*b); // Removed unnecessary 'buffer' variable
        while ((b_node->next))
        {
            b_node->s_index = i;
            i++;
            b_node = b_node->next;
        }
        b_node->s_index = i;
        ft_clean(&b_node);
        ft_subcostassigner(node, b_node, a_size, b);
    }
}

// b_node will be the one we look for 
void	ft_subcostassigner(t_value *node, t_value *b_node
	, int a_size, t_value **b)
{
	int	b_size;

	b_node = ft_search_by_value(b, ft_find_closest_smaller(b, node->value));
	b_size = ft_stack_size(b);
	a_size = ft_stack_size(&node);
	b_node->move_up = b_node->s_index;
	b_node->mover_two = b_size - b_node->s_index;
	node->b_value = b_node->value;
	node->move_up = node->s_index - 100;
	node->mover_two = a_size - node->s_index + 200;
	// if (node->move_up < node->mover_two && b_node->move_up <= node->move_up)
	// 	node->cost = node->move_up;
	// else
	// // 	node->cost = node->mover_two;
	// ft_pntf("Cost assigned to %i   is %i up and %i down", node->value, node->move_up, node->mover_two);
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
	ft_clean(a);
	ft_clean(b);
}

t_value *ft_lowest_cost(t_value **a)
{
    t_value *buffer;
    t_value *lowest_node; 
    int     current_cheapest;

    buffer = *a;
    current_cheapest = INT_MAX;
    lowest_node = NULL;  

    if (buffer->cost == 0)  // Check for special case?
        return (buffer); 

    while (buffer->next != 0)
    {
        if (buffer->cost < current_cheapest)
        {
            current_cheapest = buffer->cost;
            lowest_node = buffer; 
        }
        buffer = buffer->next;
    }

    return (lowest_node); 
}

//a's have some value(cost) -- i want to find the
void	ft_subfindmove(t_value **a, t_value **b)
{
	t_value	*a_wil_be_moved;
	int		direction;
	int		b_head_value;

	a_wil_be_moved = ft_lowest_cost(a);
	b_head_value = ft_find_closest_smaller(b, a_wil_be_moved->value);
	ft_pntf("A shall be %i and B shell be %i", a_wil_be_moved->value, b_head_value);
	ft_pntf("A shall is  %i and B shell is %i", (*a)->value, (*b)->value);
	direction = ft_direction(a);
	ft_pntf("direction shall be %i", direction);
	// printf("%i -- a_will_be_moved ; %i -- b_head_value\n", a_wil_be_moved->value, b_head_value);
	if (direction)
	{
		while ((*b)->value != b_head_value && (*a)->value != a_wil_be_moved->value)
		{
				ft_clean(a);
				ft_clean(b);
				ft_moves_rr(b, a);
		}
		while (!((*a)->value == a_wil_be_moved->value))
		{
			ft_clean(a);
			ft_clean(b);
			ft_moves_ra(a);
		}
		while (!((*b)->value == b_head_value))
		{
			ft_clean(b);
			ft_moves_rb(b);
		}
	}
	else if (direction == 0)
		ft_subsubfindmove(a, b, a_wil_be_moved->value, b_head_value);
}

//add function utilizing the COST aspect of the t_value
//allign the two nodes and than when findmove exits, it does pb
//go through each node in the t_value chain, assign cost
void	ft_findmove(t_value **a, t_value **b)
{
	ft_clean(a);
	if (*b && (*b)->next)
	{
		ft_cost_assigner_macro(a, b);
		ft_subfindmove(a, b);
	}
	if (*b)
		ft_clean(b);
}
