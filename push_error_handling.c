/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:56 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 20:14:22 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_allocation_failure(char *str)
{
	ft_printf("allocation failure : %s\n", str);
	exit(EXIT_FAILURE);
}
