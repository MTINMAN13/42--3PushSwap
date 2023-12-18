/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:34:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifvalid(t_value** values)
{
	t_value	*current;
	int 	current_value;

	current = *values;
	while (current != NULL)
	{
		current_value = current->value;
		t_value* temp = current->next;
		while (temp != NULL)
		{
			if (temp->value == current_value)
			{
				// Duplicate found
				ft_pntf("error dupe value at %i", current_value);
				ft_clean(values);
				return (0); // Invalid
			}
			temp = temp->next;
		}
		current = current->next;
	}
	ft_clean(values);
	return 1; // Valid
}

t_value	*ft_init(int size, char **values)
{
	int		i;
	t_value	*head;

	i = 1;
	head = ft_new_head(ft_atoi(values[i]));
	while (size > 2)
	{
		ft_add_back(&head, ft_atoi(values[i+1]), i);
		size--;
		i++;
	}
	return (head);
}

t_value	*ft_new_head(int value)
{
	t_value *temp;

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

void	ft_free(t_value **head)
{
	t_value	*current;
	t_value	*next_node;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL;
}
