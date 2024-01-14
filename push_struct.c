/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:11:50 by mman              #+#    #+#             */
/*   Updated: 2024/01/13 18:12:15 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_value	*ft_new_head(int value)
{
	t_value	*temp;

	temp = (t_value *)malloc(sizeof(t_value));
	if (temp == NULL)
		ft_allocation_failure("ft_new_head");
	temp->value = value;
	temp->s_index = 0;
	temp->prev = NULL;
	temp->next = NULL;
	return (temp);
}

void	ft_add_back(t_value **head, int value, int index)
{
	t_value	*new_value;
	t_value	*current;

	new_value = (t_value *)malloc(sizeof(t_value));
	if (new_value == NULL)
		ft_allocation_failure("ft_add_back");
	if ((*head)->value == 0)
		*head = new_value;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_value;
		new_value->prev = current;
		new_value->value = value;
		new_value->s_index = index;
		new_value->next = NULL;
	}
}
