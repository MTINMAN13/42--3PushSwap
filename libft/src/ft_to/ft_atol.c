/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:26:54 by mman              #+#    #+#             */
/*   Updated: 2024/06/11 21:06:59 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//converts the initial portion of the string pointed to by str to long 
//representation.

long	ft_atol(const char *str)
{
	int		c;
	long	r;
	long	s;

	c = 0;
	r = 0;
	s = 1;
	while ((str[c] > 8 && str[c] < 14) || str[c] == 32)
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		r = r * 10 + (str[c] - 48);
		c++;
	}
	return (r * s);
}
/*
int	main(void)
{
	char	str[] = "054854";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}
*/
