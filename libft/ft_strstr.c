/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:56:29 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/03/30 16:50:48 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	rozm;
	size_t	index;

	rozm = 0;
	index = 0;
	if (!*needle)
		return ((char*)haystack);
	while ((char)haystack[rozm++ + index] && !(index = 0))
		while ((char)haystack[rozm + index - 1] == needle[index])
			if (!(char)needle[++index])
				return ((char*)&haystack[rozm - 1]);
	return (NULL);
}
