/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swpu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:32:30 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 23:10:41 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char x)
{
	int		l;
	t_stack	*aux_1;
	t_stack	*aux_2;
	t_stack	*aux_3;

	l = ft_stacksize(stack);
	aux_1 = *stack;
	aux_2 = (*stack)->next;
	aux_3 = ((*stack)->next)->next;
	if (l > 1)
	{
		aux_2->next = *stack;
		aux_1->next = aux_3;
		*stack = aux_2;
		if (x == 'a')
			ft_printf("sa\n");
		if (x == 'b')
			ft_printf("sb\n");
	}
}

void	ft_swapab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 'x');
	ft_swap(stack_b, 'x');
	ft_printf("ss\n");
}

void	ft_pushb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a1;
	t_stack	*node_b1;

	if (*stack_a == NULL)
		return ;
	node_a1 = *stack_a;
	if ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	else
		*stack_a = NULL;
	if (*stack_b == NULL)
	{
		*stack_b = node_a1;
		node_a1->next = NULL;
	}
	else
	{
		node_b1 = *stack_b;
		*stack_b = node_a1;
		node_a1->next = node_b1;
	}
	ft_printf("pb\n");
}

void	ft_pusha(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_b1;
	t_stack	*node_a1;

	if (*stack_b != NULL)
	{
		node_b1 = *stack_b;
		if ((*stack_b)->next)
			*stack_b = (*stack_b)->next;
		else
			*stack_b = NULL;
		if (*stack_a == NULL)
		{
			*stack_a = node_b1;
			node_b1->next = NULL;
		}
		else
		{
			node_a1 = *stack_a;
			*stack_a = node_b1;
			node_b1->next = node_a1;
		}
		ft_printf("pa\n");
	}
}
