/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_initiate_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/01/13 19:13:01 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifvalid(t_value **values)
{
	t_value	*current;
	t_value	*temp;
	int		current_value;

	current = *values;
	temp = current->next;
	while (current != NULL)
	{
		current_value = current->value;
		while (temp != NULL)
		{
			if (temp->value == current_value)
			{
				ft_clean(values);
				return (0);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	ft_clean(values);
	return (1);
}

static t_value	*ft_parser(t_value	*head, char **values)
{
	char	**split;
	int		i;

	i = 1;
	// TODO go through values[1] and look for non-integer (+ " " and "-")
	split = ft_split(values[1], ' ');
	if (split && *split)
	{
		ft_pntf("%c", *split[0]);
		head = ft_new_head(ft_atoi(*split));
		split++;
		while (*split)
		{
			if (ft_isdigit(*split[0]) == 0)
				ft_error();
			ft_add_back(&head, ft_atoi(*split), i);
			split++;
			i++;
		}
		free_split_result(split - i);
	}
	return (head);
}

t_value	*ft_init(int size, char **values)
{
	int		i;
	t_value	*head;

	i = 1;
	head = NULL;
	if (size == 2)
	{
		head = ft_parser(head, values);
	}
	else
	{
		// TODO go through values and look for non-integer (+ " " and "-")
		head = ft_new_head(ft_atoi(values[i]));
		while (size > 2)
		{
			ft_add_back(&head, ft_atoi(values[i + 1]), i);
			size--;
			i++;
		}
	}
	return (head);
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
