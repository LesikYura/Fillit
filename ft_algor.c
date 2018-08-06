/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:18:59 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/01 17:03:44 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_expand(int count, int raws, int retry)
{
	char	*sfin;
	int		i;
	int		strlen;

	if (raws == 0)
	{
		strlen = count * 4;
		while (ft_sqrt(strlen) == 0)
			++strlen;
		raws = ft_sqrt(strlen);
	}
	raws += retry;
	sfin = ft_strnew(raws * raws + raws);
	i = 0;
	while (i < raws * raws + raws)
	{
		if ((i + 1) % (raws + 1) == 0)
			sfin[i++] = '\n';
		else
			sfin[i++] = '.';
	}
	sfin[i] = '\0';
	return (sfin);
}

int		ft_readd(char *sfin, char *str, int *flag, int c)
{
	int start;
	int ret;

	start = 0;
	while (sfin[start] != 'A' + c && sfin[start])
		++start;
	if (sfin[start] == '\0')
		ret = ft_add(sfin, str, c, -1);
	else
	{
		ft_clear(sfin, c);
		ret = ft_add(sfin, str, c, start);
	}
	if (ret)
		flag[c] = 1;
	else
		flag[c] = 0;
	return (ret);
}

void	ft_trackslow(char *sfin, char **str, int j, int *flag)
{
	int i;

	if (j == ft_count(flag))
		return ;
	i = -1;
	while (++i < ft_count(flag))
	{
		if (flag[i] == 0)
		{
			while (1)
			{
				if (ft_ok(flag))
					return ;
				if (ft_readd(sfin, str[i], flag, i))
					ft_trackslow(sfin, str, j + 1, flag);
				else
					break ;
			}
		}
	}
}

void	ft_trackfast(char *sfin, char **str, int j, int *flag)
{
	int i;

	if (j == ft_count(flag))
		return ;
	i = -1;
	while (++i < ft_count(flag))
	{
		if (flag[i] == 0)
		{
			if (ft_add(sfin, str[i], i, -1))
			{
				++flag[ft_count(flag)];
				flag[i] = 1;
				ft_trackfast(sfin, str, j + 1, flag);
				if (ft_ok(flag) || ft_end(flag))
					return ;
				ft_clear(sfin, i);
				flag[i] = 0;
			}
			else
				return ;
		}
	}
}

char	*ft_algor(char **str, int count)
{
	int		*flag;
	char	*sfin;
	int		retry;
	int		raws;

	retry = 0;
	flag = ft_strflag(count);
	sfin = ft_expand(count, 0, 0);
	raws = ft_raws(sfin);
	while (!ft_ok(flag))
	{
		if (count > 4)
			ft_trackfast(sfin, str, 0, flag);
		else
			ft_trackslow(sfin, str, 0, flag);
		if (!ft_ok(flag))
		{
			retry++;
			flag = ft_strflag(count);
			ft_strdel(&sfin);
			sfin = ft_expand(count, raws, retry);
		}
	}
	return (sfin);
}
