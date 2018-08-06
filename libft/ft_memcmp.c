/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:07:41 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 12:29:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *ss1;
	char *ss2;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	while (n--)
		if (*ss1++ != *ss2++)
			return ((unsigned char)*(ss1 - 1) - (unsigned char)*(ss2 - 1));
	return (0);
}
