/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:11:38 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 17:36:23 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_pow(size_t nb, int pow)
{
	unsigned long long num;

	if (nb == 0)
		return (0);
	num = 1;
	while (pow-- && nb)
		num *= nb;
	return (num);
}
