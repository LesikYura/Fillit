/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:31:38 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/01 16:57:11 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clearbreak(char *sfin, int c, int *counter)
{
	ft_clear(sfin, c);
	*counter = 5;
}

int		ft_add(char *sfin, char *str, int c, int i)
{
	int		counter;
	char	*flag;
	int		ret;

	ret = 0;
	flag = ft_blocks(str);
	while (sfin[++i] && counter != 4)
	{
		if (sfin[i] == '.')
		{
			counter = 0;
			while (counter < 4)
			{
				if (sfin[ft_addr(i, flag, counter, ft_raws(sfin))] == '.')
					sfin[ft_addr(i, flag, counter++, ft_raws(sfin))] = 'A' + c;
				else
					ft_clearbreak(sfin, c, &counter);
				if (counter == 4)
					ret = 1;
			}
		}
	}
	ft_strdel(&flag);
	return (ret);
}

int		ft_ok(int *str)
{
	int i;

	i = 0;
	while (i < ft_count(str))
	{
		if (str[i++] == 0)
			return (0);
	}
	return (1);
}

int		ft_end(int *str)
{
	if (str[ft_count(str)] > 20000000)
		return (1);
	return (0);
}

int		*ft_strflag(int count)
{
	int		*str;
	int		i;

	if (!(str = (int*)malloc(sizeof(int) * (count + 2))))
		return (NULL);
	i = 0;
	while (i <= count)
		str[i++] = 0;
	str[i] = -1;
	return (str);
}
