/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:25:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/20 17:08:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arg_to_array(t_list *list)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (list)
	{
		array[i] = ft_strdup(((t_arg *) list->content)->arg);
		if (array[i] == NULL)
		{
			ft_free_deep(array);
			return (NULL);
		}
		++i;
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}
