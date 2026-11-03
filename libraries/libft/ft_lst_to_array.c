/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:04:38 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 16:01:08 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_array(t_list *list)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (list)
	{
		array[i] = ft_strdup(list->content);
		if (array[i] == NULL)
		{
			ft_free_deep(array);
			return (NULL);
		}
		i++;
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}
