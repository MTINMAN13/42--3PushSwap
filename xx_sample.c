/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_sample.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2024/03/26 20:49:33 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_member
{
	int				value;
	int				s_index; //search index?? distance to top
	int				cost;
	int				distance_to_end; //how far does it have to go?
	int				b_value; //what is the value of node which needs to be top? (B)
	struct s_member	*next;
	struct s_member	*prev;
}				t_value;

// N E W  -- will use Cost to align A with B
// if something messes up, comment this and uncomment the other one
static void	ft_smart_mover(t_value **list)
{
	if ((*list)->s_index < (ft_list_size(list) / 2))
		ft_moves_ra(list);
	else
		ft_moves_rra(list);
}

void	ft_subfindmove(t_value **a, t_value **b)
{

}
//  O L D
//finds the largest value and aligns the stacks in order to move them (only ra!)
// void	ft_subfindmove(t_value **a, t_value **b)
// {
// 	t_value	*blast;
// 	int		biggest_b;
// 	int		i;

// 	i = 1;
// 	biggest_b = ft_biggestvalueinstack(b);
// 	blast = ft_last(b);
// 	ft_clean(b);
// 	if (!((*a)->value > (*b)->value) || !(blast->value < (*a)->value))
// 	{
// 		while (!((*b)->value < (*a)->value) && !((*a)->value < blast->value)
// 			&& i < 10
// 			&& !(((*a)->value < blast->value) && ((*b)->value > blast->value)))
// 		{
// 			if (!((*a)->value > (*b)->value) && biggest_b != (*b)->value)
// 				ft_moves_ra(a);
// 			i++;
// 		}
// 	}
// 	ft_clean(a);
// 	ft_clean(b);
// }

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
		ft_cost_assigner(nodee, b);
		nodee = next_node;
	}
	while ((*a)->prev)
		(*a) = (*a)->prev;
}

void	ft_cost_assigner(t_value *node, t_value **b)
{
	t_value	*b_node;
	int		valueone;
	int		cost;

	cost = 0;
	if ((*b) != 0 && (*b)->next != 0 && (*b)->next->next != 0)
	{
		b_node = *b;
		while (!(b_node->value < node->value) && b_node->next != 0)
			b_node = b_node->next;
		// while (!(b_node->value < node->value && b_node->s_index == 0
		// 		&& ((ft_last(b))->value > node->value
		// 			|| b_node->value == ft_biggestvalueinstack(b))))
		// 	b_node = b_node->next;
		valueone = b_node->value;
		if (node->s_index < (ft_list_size(&node) / 2))
			cost = node->s_index;
		else
			cost = node->s_index - (node->s_index % (ft_list_size(&node) / 2));
		cost += b_node->s_index;
	}
	node->cost = cost;
	node->s_index = valueone;
}

//add function utilizing the COST aspect of the t_value
//go through each node in the t_value chain, assign cost
void	ft_findmove(t_value **a, t_value **b)
{
	ft_cost_assigner_macro(a, b);
	if (*b)
	{
		if ((*b)->next)
			ft_subfindmove(a, b);
		ft_clean(b);
	}
}
