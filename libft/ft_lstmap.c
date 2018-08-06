/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:09:43 by nnaumenk          #+#    #+#             */
/*   Updated: 2018/04/04 16:27:46 by nnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*my;
	t_list	*start;

	if (!lst)
		return (NULL);
	if (!(my = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	my = f(lst);
	if (!my)
		return (NULL);
	start = my;
	while (lst->next)
	{
		lst = lst->next;
		my->next = f(lst);
		my = my->next;
	}
	return (start);
}
