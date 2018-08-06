/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:05:37 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 12:10:34 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strwords(char const *s, char c)
{
	int		words;
	size_t	i;

	i = 0;
	words = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if ((char)s[i] == c && (char)s[i + 1] != c && (char)s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}
