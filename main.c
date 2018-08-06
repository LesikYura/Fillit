/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:37:34 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/05/01 16:51:11 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**str;
	char	*inp;
	char	*sfin;
	int		count;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file_name\n");
		return (0);
	}
	inp = read_input(argv[1]);
	if (inp == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((count = count_block(inp)) > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	str = ft_strsplit(inp, '*');
	sfin = ft_algor(str, count);
	ft_putstr(sfin);
	return (0);
}
