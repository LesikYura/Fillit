/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:25:17 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/26 18:25:17 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		field_valid(char *str)
{
	size_t	i;
	int		symbol;
	int		n_l;

	i = 0;
	symbol = 0;
	n_l = 0;
	while (i <= ft_strlen(str))
	{
		if ((str[i] == '.' || str[i] == '#') && n_l != 4)
			symbol++;
		else if (symbol == 4 && str[i] == '\n')
		{
			n_l++;
			symbol = 0;
		}
		else if ((n_l == 4 && str[i] == '\n') || (n_l == 4 && str[i] == '\0'))
			n_l = 0;
		else
			return (1);
		i++;
	}
	if ((symbol != 0 || n_l != 0) || str[0] == '\0')
		return (1);
	return (0);
}

int		valid_figure_result(int connect, char c1, char c2)
{
	if ((connect != 0) || (c1 == '\n' && c2 == '\n'))
		return (1);
	else
		return (0);
}

int		valid_figure_hash(char *str, int connect, int i, int figure_count)
{
	if (str[i + 1] == '#')
		connect++;
	if ((i + 5) < (figure_count * 21) && str[i + 5] == '#')
		connect++;
	return (connect);
}

int		valid_figure_chek_connect(int *connect, int *dies, int *y)
{
	if ((*connect == 3 || *connect == 4) && *dies == 4)
		*connect = 0;
	else
		return (1);
	*y = 0;
	*dies = 0;
	return (0);
}

int		valid_figure(char *str, int i, int dies, int connect)
{
	int y;
	int figure_count;

	y = 1;
	figure_count = 1;
	while (str[i])
	{
		if (dies > 4)
			return (1);
		if (str[i] == '#')
		{
			connect = valid_figure_hash(str, connect, i, figure_count);
			dies++;
		}
		else if (str[i] == '\n' && y < 4)
			y++;
		else if (str[i] == '\n' && y == 4)
		{
			if (valid_figure_chek_connect(&connect, &dies, &y) == 1)
				return (1);
			figure_count++;
		}
		i++;
	}
	return (valid_figure_result(connect, str[i - 1], str[i - 2]));
}
