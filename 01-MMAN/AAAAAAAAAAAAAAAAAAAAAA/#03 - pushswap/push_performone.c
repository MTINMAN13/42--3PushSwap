/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_performone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:35:19 by mman              #+#    #+#             */
/*   Updated: 2023/12/19 00:14:56 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first element becomes the last one.
void	ft_firsttolast(t_value **list)
{
	t_value	*first;
	t_value	*last;

	first = ft_util_reset_head(list);
	last = first;
	while (last->next)
	{
		last = last->next;
	}
	first->next->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	first->s_index = last->s_index + 1;
}

// The first element becomes the last one.
void	ft_moves_ra(t_value **list)
{
	t_value	*crawl;

	crawl = ft_util_reset_head(list);
	ft_firsttolast(&crawl);
	ft_lstitr(crawl, ft_rotate);
	while (crawl->prev)
		crawl = crawl->prev;
	(*list) = crawl;
	ft_clean(list);
	ft_printf("ra\n");
}

void	ft_moves_sa(t_value **list)
{
	t_value	*newtwo;
	t_value	*newone;

	if (!list)
		ft_error();
	newtwo = *list;
	newone = ft_search_by_index(list, 0);
	if (list)
	{
		newone->next->prev = newtwo;
		newtwo->next = newone->next;
		newtwo->s_index = 1;
		newone->s_index = 0;
		newone->prev = NULL;
		newone->next = newtwo;
		newtwo->prev = newone;
		ft_printf("sa\n");
	}
	else
		ft_error();
	while ((*list)->prev)
		(*list) = (*list)->prev;
}

void	ft_lasttofirst(t_value **list)
{
	t_value	*crawl;
	t_value	*last;

	crawl = ft_util_reset_head(list);
	last = crawl;
	while (last->next)
	{
		last = last->next;
	}
	last->next = crawl;
	crawl->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->s_index = -1;
}

// The last element becomes the first one.
void	ft_moves_rra(t_value **list)
{
	t_value	*crawl;

	crawl = ft_util_reset_head(list);
	ft_lasttofirst(&crawl);
	ft_lstitr(crawl, ft_reverse_rotate);
	while (crawl->prev)
		crawl = crawl->prev;
	(*list) = crawl;
	ft_printf("rra\n");
}
