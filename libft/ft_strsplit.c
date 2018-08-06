/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:18:30 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/12 15:18:12 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_strwords(s, c) + 1))))
		return (NULL);
	while (i[2] <= ft_strlen(s))
	{
		if ((i[2] - i[0]) && ((char)s[i[2]] == c || (char)s[i[2]] == '\0'))
		{
			str[i[1]++] = ft_strsub(s, i[0], i[2] - i[0]);
			i[0] = i[2] + 1;
		}
		else if ((char)s[i[2]] == c)
			i[0]++;
		i[2]++;
	}
	str[i[1]] = NULL;
	return (str);
}
