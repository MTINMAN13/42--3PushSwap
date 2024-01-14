/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_initiate_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/01/14 19:45:29 by mman             ###   ########.fr       */
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

static void	ft_validator(char *values)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(values);
	if (ft_atoi(values) > INT_MAX || ft_atoi(values) < INT_MIN)
		ft_error();
	while (len > i)
	{
		if (ft_isdigit((int)values[i]) == 0)
			ft_error();
		i++;
	}
	i = 0;
}

// assigns values to the structure, when parsed from a single stirng ""
static t_value	*ft_parser(t_value	*head, char **values)
{
	char	**split;
	int		i;

	i = 1;
	ft_validator(values[1]);
	split = ft_split(values[1], ' ');
	if (split && *split)
	{
		head = ft_new_head(ft_atoi(*split));
		split++;
		while (*split)
		{
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
		ft_validator(values[i]);
		head = ft_new_head(ft_atoi(values[i]));
		while (size > 2)
		{
			ft_add_back(&head, ft_atoi(values[i + 1]), i);
			ft_validator(values[i + 1]);
			size--;
			i++;
		}
	}
	return (head);
}
