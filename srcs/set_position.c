/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:11:50 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 23:21:36 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_position(t_stack **stack)
{
	t_stack	*aux;
	int		pos;

	aux = *stack;
	pos = 0;
	while (aux)
	{
		aux->pos = pos;
		aux = aux->next;
		pos++;
	}
}

int	ft_get_higher_index_position(t_stack **stack)
{
	t_stack	*aux;
	int		higher_pos;
	int		higher_index;

	aux = *stack;
	ft_get_position(stack);
	higher_index = INT_MIN;
	higher_pos = aux->pos;
	while (aux)
	{
		if (aux->index > higher_index)
		{
			higher_index = aux->index;
			higher_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (higher_pos);
}

int	ft_get_lowest_index_position(t_stack **stack)
{
	t_stack	*aux;
	int		lowest_pos;
	int		lowest_index;

	aux = *stack;
	ft_get_position(stack);
	lowest_index = INT_MAX;
	lowest_pos = aux->pos;
	while (aux)
	{
		if (aux->index < lowest_index)
		{
			lowest_index = aux->index;
			lowest_pos = aux->pos;
		}
		aux = aux->next;
	}
	return (lowest_pos);
}

int	ft_get_target(t_stack **stack_a, int index_b, int t_index, int t_pos)
{
	t_stack	*aux_a;

	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index > index_b && aux_a->index < t_index)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->index < t_index)
		{
			t_index = aux_a->index;
			t_pos = aux_a->pos;
		}
		aux_a = aux_a->next;
	}
	return (t_pos);
}

void	ft_set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		t_pos;
	t_stack	*aux_b;

	t_pos = 0;
	aux_b = *stack_b;
	ft_get_position(stack_a);
	ft_get_position(stack_b);
	while (aux_b)
	{
		t_pos = ft_get_target(stack_a, aux_b->index, INT_MAX, t_pos);
		aux_b->target = t_pos;
		aux_b = aux_b->next;
	}
}
