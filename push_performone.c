/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:35:19 by mman              #+#    #+#             */
/*   Updated: 2023/12/11 20:35:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first element becomes the last one.
void	ft_firsttolast(t_value **crawl)
{
	t_value	*c;

	c = *crawl;
	while (c->s_index != -1)
		c = c->prev;
}

void	ft_moves_ra(t_value **list)
{
	if (list)
	{
		// Increment everythin - 1
		// first becomes last
		ft_lstitr(*list, ft_rotate);
		ft_pntf("ra");
	}
	else
		ft_error();
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ft_moves_sa(t_value **list)
{
	t_value	*newtwo;
	t_value	*newone;
	t_value	*three;

	if (!list)
		ft_error();
	newtwo = *list;
	// two is node with s_index 1
	newone = ft_search_by_index(list, 1);
	three = newone->next;
	if (list)
	{
		newtwo->s_index = 1;
		newone->s_index = 0;
		newone->prev = NULL;
		newone->next = newtwo;
		newtwo->prev = newone;
		newtwo->next = three;
		three->prev = newtwo;
		ft_printf("sa\n");
	}
	else
		ft_error();
}

void ft_lasttofirst(t_value **list)
{
	t_value	*c;
	t_value *two;

	if (!list)
		ft_error();
	c = *list;
	// two is node with s_index 1
	two = ft_search_by_index(list, 1);
	if (c)
	{
		while (c->next)
			c = c->next;
		c->s_index = 0;
		c->prev->next = NULL;
		c->prev = NULL;
		c->next = two;
		two->prev = c;
		ft_pntf("last to first %i", c->value);
	}
	else
		ft_error();
}

// The last element becomes the first one.
void	ft_moves_rra(t_value **list)
{
	if (list)
	{
		ft_lstitr(*list, ft_reverse_rotate);
		ft_lasttofirst(list);
		ft_printf("rra\n");
	}
	else
		ft_error();
	fullstack(*list);
}
