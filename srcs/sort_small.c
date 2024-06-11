/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:30:40 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 22:55:25 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->index > ((*stack)->next)->index)
		ft_rx(stack, 'a');
}

void	sort_3(t_stack **stack)
{
	int	higher;

	higher = get_higher_index_position(stack);
	if (higher == 0)
		ft_rx(stack, 'a');
	else if (higher == 1)
		ft_rrx(stack, 'a');
	if ((*stack)->index > ((*stack)->next)->index)
		ft_swap(stack, 'a');
}

void	sort_4(t_stack	**stack_a, t_stack **stack_b)
{
	int	smaller;

	smaller = get_lowest_index_position(stack_a);
	if (smaller > 1)
	{
		while (smaller < 4)
		{
			ft_rrx(stack_a, 'a');
			smaller++;
		}
	}
	else if (smaller < 2)
	{
		while (smaller > 0)
		{
			ft_rx(stack_a, 'a');
			smaller--;
		}
	}
	if (is_sorted(*stack_a))
		return ;
	ft_pushb(stack_a, stack_b);
	sort_3(stack_a);
	ft_pusha(stack_a, stack_b);
}

void	sort_5(t_stack	**stack_a, t_stack **stack_b)
{
	int	smaller;

	smaller = get_lowest_index_position(stack_a);
	if (smaller > 1)
	{
		while (smaller < 5)
		{
			ft_rrx(stack_a, 'a');
			smaller++;
		}
	}
	else if (smaller < 2)
	{
		while (smaller > 0)
		{
			ft_rx(stack_a, 'a');
			smaller--;
		}
	}
	if (is_sorted(*stack_a))
		return ;
	ft_pushb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	ft_pusha(stack_a, stack_b);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size_start == 2)
		sort_2(stack_a);
	if ((*stack_a)->size_start == 3)
		sort_3(stack_a);
	if ((*stack_a)->size_start == 4)
		sort_4(stack_a, stack_b);
	if ((*stack_a)->size_start == 5)
		sort_5(stack_a, stack_b);
}
