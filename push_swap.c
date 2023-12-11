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

int	ft_checksorted(t_value *list)
{
	if (list)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_value	*a;

	a = ft_init(argc, argv);
	if (!a || ft_checkifvalid(&a)) // check if it initiated properly
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a)) // check if it isnt already sorted
	{
		ft_pntf("not sorted");
		ft_sort(&a);        // perform the shabang
	}
	ft_free(&a);
	return (0);
}




// void	ft_sort(t_value **stack_a)
// {
// 	t_value	*stack_b;

// 	stack_b = NULL;
// 	if (ft_sizeof(stack_a) == 3)
// 	{

// 	}

// }


/*
smallest list of instructions possible to sort the stack
a, the smallest number being at the top.



// Find the "slot"

--	X --
 BIGGER -slot- SMALLER
SMALLEST IN STACK -slot- SMALLER








*/
