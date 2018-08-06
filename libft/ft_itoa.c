/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:37:53 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/12 13:53:54 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		znak;
	char	*str;
	int		rozm;

	rozm = ft_numcount(n);
	znak = 0;
	if (n < 0)
		znak = 1;
	if (!(str = (char *)malloc(sizeof(char) * (ft_numcount(n) + 1 + znak))))
		return (NULL);
	str[ft_numcount(n) + znak] = '\0';
	str[0] = '0';
	while (n)
	{
		str[ft_numcount(n) - 1 + znak] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (znak)
		str[0] = '-';
	return (str);
}
