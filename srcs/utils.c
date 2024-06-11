/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:30:53 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 22:55:17 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printerror(char *str)
{
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	print_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		while (aux->next)
		{
			ft_printf("Value: %d index: %d \n", aux->value, aux->index);
			aux = aux->next;
		}
		ft_printf("Value: %d index: %d\n", aux->value, aux->index);
	}
	else
		ft_printf("Empty stock\n");
}

void	print_stack_tg(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (aux)
	{
		while (aux)
		{
			ft_printf("Value: %d tget: %d\n", aux->value, aux->target);
			aux = aux->next;
		}
	}
	else
		ft_printf("Empty stock\n");
}
