/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_performtwo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:35:19 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 19:33:50 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_pb(t_value **a, t_value **b)
{
	t_value	*a_new;

	ft_clean(a);
	// ft_pntf("i will be moving %i", (*a)->value);
	a_new = (*a)->next;
	if (*b)
	{	
		ft_clean(b);
		ft_lstitr(*b, ft_reverse_rotate);
		(*a)->next = (*b);
		(*b)->prev = (*a);
	}
	else
	{
		(*b) = (*a);
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	(*a)->s_index = (*b)->s_index - 1;
	if (a_new != 0)
	{
		a_new->prev = NULL;
		ft_lstitr(a_new, ft_reverse_rotate);
	}
	(*a) = a_new;
	while ((*b)->prev)
		(*b) = (*b)->prev;
	// ft_pntf("new head is %i", (*a)->value);
	ft_pntf("pb");
}

void	ft_moves_pa(t_value **a, t_value **b)
{
	t_value	*b_new;

	ft_lstitr(*a, ft_reverse_rotate);
	while ((*a)->prev)
		(*a) = (*a)->prev;
	while ((*b)->prev)
		(*b) = (*b)->prev;
	b_new = (*b)->next;
	(*a)->prev = (*b);
	(*b)->s_index = (*a)->s_index - 1;
	(*b)->next = (*a);
	if (b_new != 0)
	{
		b_new->prev = NULL;
		ft_lstitr(b_new, ft_reverse_rotate);
	}
	(*b) = b_new;
	while ((*a)->prev)
		(*a) = (*a)->prev;
	ft_pntf("pa");
}

void	ft_moves_rb(t_value **b)
{
	ft_m_rb(b);
	ft_printf("rb\n");
}

void	ft_m_rb(t_value **b)
{
	t_value	*crawl;

	crawl = ft_util_reset_head(b);
	ft_firsttolast(&crawl);
	ft_lstitr(crawl, ft_rotate);
	while (crawl->prev)
		crawl = crawl->prev;
	(*b) = crawl;
	ft_clean(b);
}

void	ft_moves_rr(t_value **a, t_value **b)
{
	ft_m_rb(b);
	ft_m_ra(a);
	ft_printf("rr\n");
}

void	ft_moves_rrr(t_value **a, t_value **b)
{
	t_value	*crawl;
	t_value	*crawlb;

	crawl = ft_util_reset_head(a);
	ft_lasttofirst(&crawl);
	ft_lstitr(crawl, ft_reverse_rotate);
	while (crawl->prev)
		crawl = crawl->prev;
	(*a) = crawl;
	ft_clean(a);
	crawlb = ft_util_reset_head(b);
	ft_firsttolast(&crawl);
	ft_lstitr(crawlb, ft_reverse_rotate);
	while (crawlb->prev)
		crawlb = crawlb->prev;
	(*b) = crawlb;
	ft_clean(b);
	ft_printf("rrr\n");
}
