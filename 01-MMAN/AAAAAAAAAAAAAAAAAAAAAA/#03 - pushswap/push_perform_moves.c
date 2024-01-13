/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_o_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:35:19 by mman              #+#    #+#             */
/*   Updated: 2023/12/06 20:35:21 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_lstitr(t_value *lst, void (*f)(void*))
{
	t_value	*node;
	t_value	*next_node;

	node = lst;
	while (node->prev)
		node = node->prev;
	while (node)
	{
		next_node = node->next;
		f(node);
		node = next_node;
	}
	while (lst->prev)
		lst = lst->prev;
}

// first becomes last
void	ft_rotate(void *data)
{
	t_value	*node;

	node = (t_value *)data;
	node->s_index -= 1;
}

// last becomes first
void	ft_reverse_rotate(void *data)
{
	t_value	*node;

	node = (t_value *)data;
	node->s_index += 1;
}
