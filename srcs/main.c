/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 22:53:15 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	stack_a = chkargs_initstack(argc, argv);
	if (is_sorted(stack_a))
		return (0);
	if (stack_a->size_start < 6)
		sort_small(&stack_a, &stack_b);
	else
		main_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
