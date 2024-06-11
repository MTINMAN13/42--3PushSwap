/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:30:47 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 23:48:44 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (stack == NULL)
		return (1);
	while (aux->next)
	{
		if (aux->value > (aux->next)->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	ft_shoveb(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	pushed;
	int	size;

	size = ft_stacksize(stack_a);
	i = 0;
	pushed = 0;
	while (i < size && pushed < (size / 2))
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pushb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_rx(stack_a, 'a');
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pushb(stack_a, stack_b);
		pushed++;
	}
}

/**
shifts stack depending on where the lowest index is
ensures the stack is in the right order
 */
void	ft_fin(t_stack **stack)
{
	int	size;
	int	lowest_id_pos;

	size = ft_stacksize(stack);
	lowest_id_pos = ft_get_lowest_index_position(stack);
	if (lowest_id_pos > size / 2)
	{
		while (lowest_id_pos < size)
		{
			ft_rrx(stack, 'a');
			lowest_id_pos++;
		}
	}
	else
	{
		while (lowest_id_pos > 0)
		{
			ft_rx(stack, 'a');
			lowest_id_pos--;
		}
	}
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	ft_shoveb(stack_a, stack_b);
	ft_lastthree(stack_a);
	while (*stack_b)
	{
		ft_set_target_pos(stack_a, stack_b);
		ft_get_distance(stack_a, stack_b);
		ft_perform_cheapest_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_fin(stack_a);
}
