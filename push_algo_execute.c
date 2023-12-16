/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:37:20 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:37:29 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_pa(t_value **a, t_value **b)
{
	t_value	*crawl;
	t_value	*a_new;

	crawl = *a;
	a_new = crawl->next;
	if ((*b) == 0)
	{
		(*b) = (*a);
		a_new->prev = NULL;
		(*b)->next = NULL;
		ft_lstitr(a_new, ft_rotate);
		(*a) = a_new;
		//assign a to b
		//downshift everything in a by one
		//strip the top node
		//make sure it is set to s_value 0 now
	}
	else
	{
		ft_pntf("else");
		ft_lstitr((*b), ft_reverse_rotate);
		crawl->next = (*b);
		(*b)->prev = crawl;
		a_new->prev = NULL;
		ft_lstitr(a_new, ft_rotate);
		(*a) = a_new;
		//upshift b by one
		//move first from a to b
		//hook it to next, keep prev at null
		//link first to previous first
		//downshift a by one
		//strip new first in a
	}
	while ((*a)->prev)
		(*a) = (*a)->prev;
	ft_pntf("pa");
}

// shoves most effective node from a to b
void	ft_algo_b(t_value **a, t_value **b, int size)
{
	// figure what to move
	t_value	*movin;
	int		stacksize;

	movin = *a;
	stacksize = ft_util_stacksize(*a);
	ft_pntf("size silencer %i", size);
	ft_pntf("size %i", stacksize);
	while (stacksize > 3)
	{
		ft_pntf("poppi %i", movin->value);
		// algo for efficient move !!!! TODO !!!
		ft_moves_pa(&movin, b);
		stacksize--;
	}
	(*a) = movin;
}

// rams b to a, wraps up the dd
void	ft_algo_wrap(t_value **a, t_value **b)
{
	ft_pntf("wrap up, %i", *b);
	fullstack(*a);
	fullstack(*b);
	ft_last_three(a);
	// ft_moves_rb(b);
	ft_check_descending(b); // makes sure b descending
	ft_back_to_a(a, b);
}

void	ft_back_to_a(t_value **a, t_value **b)
{
	t_value	*a_last;

	a_last = ft_last(a);
	fullstack(*a);
	fullstack(*b);
	ft_pntf("%i", b);
	while ((*b) != 0)
	{
		if (!((*b)->value > a_last->value && (*a)->value < (*b)->value))
			ft_sub_aligner(a, b);
		ft_moves_pb(a, b);
		ft_pntf("%i", b);
	}
	if (!ft_checksorted(*a))
	{
		while (!ft_checksorted(*a)) //add logic to find proper rot. !!!! TODO!!!
			ft_moves_ra(a);
		while (!ft_checksorted(*a))
			ft_moves_rra(a);
		//rra is x
		//rr otherwise
		ft_pntf("done");
		fullstack(*a);
	}
}

void	ft_sub_aligner(t_value **a, t_value **b)
{
	int		a_last;
	int		top_b;

	top_b = (*b)->value;
	a_last = ft_last(a)->value;
	while (!(top_b > a_last && (*a)->value > top_b))
	{
		ft_moves_ra(a);
		a_last = ft_last(a)->value;
	}
}

void	ft_check_descending(t_value **b)
{
	t_value	*crawl;
	int		positive_if_one;
	// int		storage;

	crawl = *b;
	positive_if_one = 1;
	while (crawl->prev)
		crawl = crawl->prev;
	// while (crawl->next)
	// {
	// 	storage = crawl->value;
	// 	crawl = crawl->next;
	// 	if (!(storage > crawl->value))
	// 		positive_if_one = 0;
	// }
	if (positive_if_one == 1)
	{
		ft_moves_rb(b);
		// ft_check_descending(b);
	}
}
