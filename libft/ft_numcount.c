/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:19:04 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 12:28:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numcount(int n)
{
	int count;

	count = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		count++;
	}
	return (count);
}
