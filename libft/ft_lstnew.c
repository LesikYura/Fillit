/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:28:47 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/04 16:19:00 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *my_list;

	if (!(my_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		my_list->content = NULL;
		my_list->content_size = 0;
	}
	else
	{
		my_list->content = ft_strdup(content);
		my_list->content_size = content_size;
	}
	my_list->next = NULL;
	return (my_list);
}
