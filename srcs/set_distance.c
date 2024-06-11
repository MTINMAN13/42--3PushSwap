/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:12:51 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 23:23:17 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief 
/// @param stack_a 
/// @param stack_b 
void	ft_get_distance(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		size_a;
	int		size_b;

	aux_b = *stack_b;
	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	while (aux_b)
	{
		aux_b->dist_b = aux_b->pos;
		if (aux_b->pos > size_b / 2)
			aux_b->dist_b = (size_b - aux_b->pos) * -1;
		aux_b->dist_a = aux_b->target;
		if (aux_b->target > size_a / 2)
			aux_b->dist_a = (size_a - aux_b->target) * -1;
		aux_b = aux_b->next;
	}
}

void	ft_move_one(t_stack **stack_a,
			t_stack **stack_b, int dist_a, int dist_b)
{
	if (dist_a < 0 && dist_b < 0)
	{
		while (dist_a < 0 && dist_b < 0)
		{
			dist_a++;
			dist_b++;
			ft_rrr(stack_a, stack_b);
		}
	}
	else if (dist_a > 0 && dist_b > 0)
	{
		while (dist_a > 0 && dist_b > 0)
		{
			dist_a--;
			dist_b--;
			ft_rr(stack_a, stack_b);
		}
	}
	ft_loop_rotate(stack_a, stack_b, dist_a, 'a');
	ft_loop_rotate(stack_a, stack_b, dist_b, 'b');
	if (*stack_b)
		ft_pusha(stack_a, stack_b);
}

int	ft_absolute_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_perform_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux_b;
	int		dist_a;
	int		dist_b;
	int		cheapest;

	aux_b = *stack_b;
	cheapest = INT_MAX;
	while (aux_b)
	{
		if (ft_absolute_value(aux_b->dist_a) + ft_absolute_value(aux_b->dist_b)
			< ft_absolute_value(cheapest))
		{
			cheapest = ft_absolute_value(aux_b->dist_a) + \
			ft_absolute_value(aux_b->dist_b);
			dist_a = aux_b->dist_a;
			dist_b = aux_b->dist_b;
		}
		aux_b = aux_b->next;
	}
	ft_move_one(stack_a, stack_b, dist_a, dist_b);
}
