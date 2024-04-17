/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2023/12/19 00:09:18 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_util_stacksize(t_value *stack)
{
	t_value	*crawl;

	crawl = ft_util_reset_head(&stack);
	while (crawl->next != NULL)
		crawl = crawl->next;
	while (stack->prev)
		stack = stack->prev;
	return (crawl->s_index + 1);
}

t_value	*ft_util_reset_head(t_value **stack)
{
	t_value	*crawl;
	t_value	*lowest_nonzero;

	crawl = *stack;
	lowest_nonzero = NULL;
	while (crawl != NULL)
	{
		if (crawl->s_index == 0)
			return (crawl);
		else if (lowest_nonzero == NULL
			|| crawl->s_index < lowest_nonzero->s_index)
			lowest_nonzero = crawl;
		crawl = crawl->prev;
	}
	if (lowest_nonzero != NULL)
		return (lowest_nonzero);
	else
	{
		ft_error();
		return (NULL);
	}
}

void	fullstack(t_value *stack)
{
	t_value	*a;
	int		nula;

	nula = 1;
	a = ft_util_reset_head(&stack);
	ft_pntf("////// FULL STACK //////");
	while (nula != 0)
	{
		ft_pntf("%i       pos %i", a->value, a->s_index);
		if (a->next == 0)
			nula = 0;
		a = a->next;
	}
	if (a != 0)
		ft_pntf("%i       pos %i", a->value, a->s_index);
	ft_pntf("////// FULL STACK //////");
}

t_value	*ft_search_by_index(t_value **stack, int searched_index)
{
	t_value	*first;
	int		current_i;

	current_i = INT_MIN;
	if (!stack || searched_index < -1)
		ft_error();
	first = ft_util_reset_head(stack);
	while (current_i != searched_index)
	{
		current_i = first->s_index;
		first = first->next;
	}
	return (first);
}

t_value	*ft_search_by_value(t_value **stack, int searched_index)
{
	t_value	*first;
	int		current_i;

	current_i = INT_MIN;
	if (!stack || searched_index < -1)
		ft_error();
	first = ft_util_reset_head(stack);
	while (current_i != searched_index)
	{
		current_i = first->value;
		first = first->next;
	}
	return (first);
}

void	ft_check_descending(t_value **b)
{
	t_value	*crawl;
	int		i;

	i = 0;
	ft_clean(b);
	crawl = *b;
	while (crawl->next && i < 10)
	{
		if (crawl->value < crawl->next->value)
		{
			ft_moves_rb(&crawl);
			i++;
		}
		crawl = crawl->next;
	}
	ft_clean(b);
}
