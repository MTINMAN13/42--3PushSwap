/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 21:02:44 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_value	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

void	ft_sort(t_value **stack_a)
{
	t_value	*stack_b;

	stack_b = NULL;
}
/*
smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
 */
