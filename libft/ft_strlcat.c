/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:55:27 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/02 18:28:41 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	rozm1;
	size_t	rozm2;

	j = 0;
	i = ft_strlen(dst);
	rozm1 = ft_strlen(src);
	rozm2 = ft_strlen(dst);
	if (i < dstsize)
		j = dstsize - i - 1;
	else
		return (dstsize + ft_strlen(src));
	while (j--)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (rozm1 + rozm2);
}
