/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutucir <rlutucir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:45:02 by rlutucir          #+#    #+#             */
/*   Updated: 2025/08/06 09:45:19 by rlutucir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_node(t_list *p, t_list **new, t_list **last)
{
	if (*new == NULL)
	{
		*new = p;
		return (1);
	}
	else if (*last)
		(*last)->next = p;
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*nc;
	t_list	*p;
	t_list	*last;
	t_list	*new;

	nc = NULL;
	last = NULL;
	new = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		nc = f(lst->content);
		p = ft_lstnew(nc);
		if (p == NULL)
		{
			ft_lstclear(&new, del);
			del(nc);
			return (NULL);
		}
		first_node(p, &new, &last);
		last = p;
		lst = lst->next;
	}
	return (new);
}
