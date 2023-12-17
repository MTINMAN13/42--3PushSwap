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
	ft_clean(a);
	ft_clean(b);
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
		ft_findmove(a, b);
		ft_moves_pa(&movin, b);
		stacksize--;
	}
	(*a) = movin;
	ft_clean(a);
}

// rams b to a, wraps up the dd
void	ft_algo_wrap(t_value **a, t_value **b)
{
	ft_pntf("wrap up, %i", *b);
	fullstack(*a);
	fullstack(*b);
	ft_last_three(a);
	ft_check_descending(b); // makes sure b descending
	fullstack(*a);
	fullstack(*b);
	ft_back_to_a(a, b);
}

void	ft_back_to_a(t_value **a, t_value **b)
{
	fullstack(*a);
	fullstack(*b);
	ft_pntf("%i", b);
	while ((*b) != 0)
	{
		ft_sub_aligner(a, b);
		ft_moves_pb(a, b);
		fullstack(*a);
		ft_pntf("%i", (*b));
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

// !((*b)->value > a_last->value && (*a)->value < (*b)->value)

void	ft_sub_aligner(t_value **a, t_value **b)
{
	int		a_last;
	int		smal;
	int		big;

	big = ft_biggestvalueinstack(a);
	smal = ft_smallestvalueinstack(a);
	a_last = ft_last(a)->value;
	// fullstack(*b);
	// ft_pntf("topb %i", top_b);
	// ft_pntf("a value %i", (*a)->value);
	// ft_pntf("a last %i", a_last);
	while (((*b)->value < smal && !(a_last == big))
					|| ((*b)->value > big && !((*a)->value == smal))
					|| (((*b)->value > smal && (*b)->value < big )
						&& !((*b)->value < (*a)->value && (*b)->value > a_last)))
	{
		ft_moves_ra(a);
		ft_clean(a);
		a_last = ft_last(a)->value;
	}
	ft_last_b(a, b);
	ft_clean(a);
	ft_clean(b);
}

void	ft_last_b(t_value **a, t_value **b)
{
	int	a_last;
	int	i;
	int	smal;
	int	big;

	smal = ft_smallestvalueinstack(a);
	big = ft_biggestvalueinstack(a);
	i = 0;
	a_last = ft_last(a)->value;
	ft_clean(b);
	ft_clean(a);
	if ((*b)->next == 0)
	{
		ft_pntf("last one bb %i", (*b)->value);
		while (i < 13
				&& (((*b)->value < smal && !(a_last == big))
					|| ((*b)->value > big && !((*a)->value == smal))
					|| (((*b)->value > smal && (*b)->value < big )
						&& !((*b)->value < (*a)->value && (*b)->value > a_last))))
		{
			ft_moves_rra(a);
			ft_clean(a);
			a_last = ft_last(a)->value;
			i++;
		}
	}
}

// top b must be smaller than top a and bigger than last a
// top b > (*a)->value && top b > last_a->value

// or last_a must be the biggest in stack
// last_a->value == biggestvalueinstack && (*a)->value > top_b

// best way would be to have the stack remember the factual sequence number

/*
	ft_pntf("%i //// %i ////// %i  ////// ", !((top_b < (*a)->value) && (top_b > a_last)), !(a_last == biggestvalueinstack && (*a)->value > top_b), (((top_b > (*a)->value) && (a_last < top_b)) || (top_b == bb && a_last == biggestvalueinstack)));
	ft_pntf("%i", (!((top_b < (*a)->value) && (top_b > a_last))
			&& !(a_last == biggestvalueinstack && (*a)->value > top_b)
			&& !(((top_b > (*a)->value) && (a_last < top_b)))
			&& !(top_b == bb && a_last == biggestvalueinstack)));
	ft_clean(a);
	while (!((top_b < (*a)->value) && (top_b > a_last))
			&& !(a_last == biggestvalueinstack && (*a)->value > top_b)
			&& !(((top_b > (*a)->value) && (a_last < top_b)))
			&& !(top_b == bb && a_last == biggestvalueinstack))

			*/
