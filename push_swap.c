/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:53:32 by mman              #+#    #+#             */
/*   Updated: 2024/03/27 00:30:26 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_value *list)
{
	int		prev;
	t_value	*crawl;

	prev = INT_MIN;
	crawl = list;
	while (crawl->prev)
		crawl = crawl->prev;
	while (prev < crawl->value)
	{
		prev = crawl->value;
		crawl = crawl->next;
		if (crawl == NULL)
			return (1);
	}
	while (crawl->prev)
		crawl = crawl->prev;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_value	*a;

	a = ft_init(argc, argv);
	if (!a || !ft_checkifvalid(&a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
	{
		ft_sort(&a);
	}
	ft_free(&a);
	return (0);
}
