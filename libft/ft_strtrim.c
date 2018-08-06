/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:08:18 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/03 12:15:47 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_trim(char const *s, size_t *start, size_t *finish)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	if (s[0] == '\0')
		return (num);
	while (s[i] <= 32 && s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			num++;
		i++;
	}
	*start = i;
	if (s[i] == '\0')
		return (num);
	i = ft_strlen(s);
	while (s[--i] <= 32)
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			num++;
	*finish = i + 1;
	return (num);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	finish;
	size_t	i;

	if (s == NULL)
		return (NULL);
	start = 0;
	finish = ft_strlen(s);
	str = ft_strnew(ft_strlen(s) - ft_trim(s, &start, &finish));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i++ < finish - start)
		str[i - 1] = s[start + i - 1];
	str[i] = '\0';
	return (str);
}
