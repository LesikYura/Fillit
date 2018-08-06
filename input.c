/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:40:46 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/27 13:40:49 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 40000

char	*buff_copy(char *buff, size_t ret)
{
	char	*res;

	res = ft_strnew(ret);
	ft_strcpy(res, buff);
	ft_strdel(&buff);
	return (res);
}

char	*read_input(char *f_name)
{
	char	*buff;
	char	*res;
	int		fd;
	int		ret;

	buff = ft_strnew(BUFF_SIZE);
	fd = open(f_name, O_RDONLY);
	buff[fd] = 0;
	if (fd == 0)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 572)
		return (NULL);
	res = buff_copy(buff, ret);
	if ((field_valid(res)) == 1)
		return (NULL);
	if ((valid_figure(res, 0, 0, 0)) == 1)
		return (NULL);
	close(fd);
	return (res);
}

int		count_block(char *str)
{
	int flag;
	int i;
	int count;

	flag = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			flag++;
			if (flag == 5)
			{
				str[i] = '*';
				flag = 0;
				count++;
			}
		}
		i++;
	}
	if (count >= 0)
		return (count + 1);
	return (count);
}
