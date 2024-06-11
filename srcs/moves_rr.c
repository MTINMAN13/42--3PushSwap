/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:33 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 22:55:58 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_stack **stack, char x)
{
	t_stack	*node_1;
	t_stack	*node_lst;

	if (*stack == NULL)
		return ;
	node_1 = *stack;
	node_lst = node_last(*stack);
	*stack = (*stack)->next;
	node_lst->next = node_1;
	node_1->next = NULL;
	if (x == 'a')
		ft_printf("ra\n");
	if (x == 'b')
		ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	ft_rx(stack_a, 'x');
	ft_rx(stack_b, 'x');
	ft_printf("rr\n");
}

void	ft_rrx(t_stack **stack, char x)
{
	t_stack	*node_lst;
	t_stack	*node_pnult;
	t_stack	*aux;

	if (*stack == NULL)
		return ;
	aux = *stack;
	while (aux->next)
	{
		if ((aux->next)->next == NULL)
			node_pnult = aux;
		aux = aux->next;
	}
	node_lst = aux;
	node_lst->next = *stack;
	*stack = node_lst;
	node_pnult->next = NULL;
	if (x == 'a')
		ft_printf("rra\n");
	if (x == 'b')
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	ft_rrx(stack_a, 'x');
	ft_rrx(stack_b, 'x');
	ft_printf("rrr\n");
}

void	ft_loop_rotate(t_stack **stack_a, t_stack **stack_b, int i, char x)
{
	while (i)
	{
		if (i < 0)
		{
			if (x == 'a')
				ft_rrx(stack_a, 'a');
			if (x == 'b')
				ft_rrx(stack_b, 'b');
			i++;
		}
		else
		{
			if (x == 'a')
				ft_rx(stack_a, 'a');
			if (x == 'b')
				ft_rx(stack_b, 'b');
			i--;
		}
	}
}
