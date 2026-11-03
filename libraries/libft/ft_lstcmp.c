/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:48:53 by nippolit          #+#    #+#             */
/*   Updated: 2024/10/14 02:55:25 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdbool.h>

bool	ft_lstcmp(t_list *lst1, t_list *lst2, size_t size)
{
	while (lst1 && lst2)
	{
		if (ft_memcmp(lst1->content, lst2->content, size) != 0)
			return (false);
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	if (lst1 == NULL && lst2 == NULL)
		return (true);
	return (false);
}
