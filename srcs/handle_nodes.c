/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 22:53:38 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	i = 1;
	aux = *stack;
	if (stack == 0)
		return (0);
	while (aux->next)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	node_addback(t_stack **stack, t_stack *node)
{
	if (node != 0)
	{
		if (*stack == 0)
		{
			*stack = node;
			(*stack)->next = NULL;
		}
		else
			node_last(*stack)->next = node;
	}
}

t_stack	*node_last(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*node_new(char *nbr)
{
	t_stack	*new_node;

	new_node = (t_stack *) malloc (sizeof (t_stack));
	if (!new_node)
		ft_printerror("\n");
	new_node->value = ft_atoi(nbr);
	new_node->next = NULL;
	return (new_node);
}
