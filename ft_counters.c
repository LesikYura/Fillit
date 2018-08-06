/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:07:52 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/26 16:11:03 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count(int *flag)
{
	int i;

	i = 0;
	while (flag[i] != -1)
		++i;
	return (i - 1);
}

int		ft_raws(char *sfin)
{
	int i;

	i = 0;
	while (sfin[i] != '\n' && sfin[i])
		++i;
	return (i);
}

int		ft_addr(int i, char *flag, int counter, int raws)
{
	int tmp1;
	int tmp2;

	tmp1 = i + flag[counter] - flag[0];
	tmp2 = (raws - 4) * (flag[counter] / 5 - flag[0] / 5);
	return (tmp1 + tmp2);
}

void	ft_clear(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'A' + c)
			str[i] = '.';
		++i;
	}
}

char	*ft_blocks(char *str)
{
	int		j;
	char	*flag;
	int		i;

	flag = ft_strnew(4);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			flag[j] = i;
			++j;
		}
		++i;
	}
	return (flag);
}
