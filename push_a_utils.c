/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:34:57 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_util_stacksize(t_value *stack)
{
	t_value	*crawl;

	crawl = ft_util_reset_head(&stack);
	while (crawl->next != NULL)
		crawl = crawl->next;
	ft_pntf("%i", crawl->s_index + 1);
	return (crawl->s_index + 1);
}

// takes in position, returns t_value with s_index 0
t_value *ft_util_reset_head(t_value **stack)
{
	t_value *crawl;
	t_value *lowest_nonzero;

	crawl = *stack;
	lowest_nonzero = NULL;
	while (crawl != NULL)
	{
		if (crawl->s_index == 0)
		{
			return (crawl);
		}
		else if (lowest_nonzero == NULL || crawl->s_index < lowest_nonzero->s_index)
		{
			lowest_nonzero = crawl;
		}
		crawl = crawl->prev;
	}
	if (lowest_nonzero != NULL)
	{
		ft_pntf("found one with the lowest nonzero index");
		return lowest_nonzero;
	}
	else
	{
		ft_error();
		return NULL;  // Adjust the return type based on your requirements
	}
}


void	fullstack(t_value *stack)
{
	t_value	*a;
	int		nula;

	nula = 1;
	a = ft_util_reset_head(&stack);
	while (nula != 0)
	{
		ft_pntf("%i", a->value);
		a = a->next;
		if (a->next == NULL)
			nula = 0;
	}
	ft_pntf("%i", a->value);
}

t_value	*ft_search_by_index(t_value **stack, int searched_index)
{
	t_value	*first;
	int		current_i;

	if (!stack || searched_index < -1)
		ft_error();
	first = ft_util_reset_head(stack);
	current_i = first->s_index;
	while (current_i != searched_index)
	{
		current_i = first->s_index;
		first = first->next;
	}
	if (current_i == searched_index)
		ft_pntf("gefunden, %i", current_i);
	return (first);
}

/*
TODO FIND BY INDEX

// give pointer to a node
// for linking purposes



*/
