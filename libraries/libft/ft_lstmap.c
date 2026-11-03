/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:00:12 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 13:13:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_cont;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	new_cont = new_list;
	while (lst && lst->next)
	{
		new_cont->next = ft_lstnew(f(lst->next->content));
		if (!new_cont-> next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_cont = new_cont-> next;
		lst = lst-> next;
	}
	return (new_list);
}
// fait une nouvelle chaine en appliquant une fonction
