/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:23:21 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 13:09:44 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*but;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		but = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = but;
	}
	*lst = NULL;
}
// supprime et libere la memoire d'une chaine
