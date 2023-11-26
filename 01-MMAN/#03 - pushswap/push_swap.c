/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:35:00 by mman              #+#    #+#             */
/*   Updated: 2023/11/24 18:00:15 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// resource : https://www.youtube.com/watch?v=K0XXVSL4wUo
// resource : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

typedef struct s_member
{
	int				value;
	int				index;

}				t_value;

t_value	*ft_initialize(int argc, char *argv[])
{
	int			amnt_of_n;
	t_value		*stackone;

	amnt_of_n = argc - 1;
	stackone = (t_value *)malloc(sizeof(t_value) * amnt_of_n);
	int i = 1;
	while (i <= amnt_of_n) {
		stackone[i - 1] = (t_value){ft_atoi(argv[i]), i - 1};
		++i;
	}
	return (stackone);
}

void	ft_sa(t_value *stackone, int amnt_of_n)
{
	if (amnt_of_n > 1) {
		// Swap the top two values
		t_value temp = stackone[0];
		stackone[0] = stackone[1];
		stackone[1] = temp;
		stackone[0].index = 0;
		stackone[1].index = 1;
		ft_printf("\nsa\n");

	}
}
/////                  ---                       PROCESSING  FUCKING LINKED LIST                    ------------           ///////////

int main(int argc, char *argv[])
{
	int			amnt_of_n;
	t_value		*stack_a;

	amnt_of_n = argc - 1;
	stack_a = ft_initialize(argc, argv);
	int j = 0;
	while (j < amnt_of_n)
	{
		ft_printf("STACK A | Element %d: value = %d, current_index = %d\n",
			   j, stack_a[j].value, stack_a[j].index);
		++j;
	}
	ft_printf("////////////////////////////\n");
	ft_sa(stack_a, amnt_of_n);
	j = 0;
	while (j < amnt_of_n)
	{
		ft_printf("STACK A | Element %d: value = %d, current_index = %d\n",
			   j, stack_a[j].value, stack_a[j].index);
		++j;
	}
	return 0;
}
