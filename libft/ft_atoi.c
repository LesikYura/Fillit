/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:18:59 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/04 16:18:13 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				znak;

	znak = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		znak = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + ((*str++ - '0') % 10);
		if (num >= 9223372036854775807 && znak == 1)
			return (-1);
		else if (num > 9223372036854775807 && znak == -1)
			return (0);
	}
	return (znak * num);
}
