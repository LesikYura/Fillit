/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:45:36 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 18:40:04 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	rozm;
	size_t	index;
	size_t	l;

	rozm = 0;
	index = 0;
	l = len;
	if (!*needle)
		return ((char*)haystack);
	while ((char)haystack[rozm++ + index] && len)
	{
		l = len--;
		index = 0;
		while ((char)haystack[rozm + index - 1] == (char)needle[index] && l)
			if ((char)needle[++index] == '\0' || !(l--))
				return ((char*)&haystack[rozm - 1]);
	}
	return (NULL);
}
