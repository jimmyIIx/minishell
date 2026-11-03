/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:25:19 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 21:08:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	process(char **array, t_env *list, int i);

char	**ft_env_to_array(t_env *list)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc((ft_lstsize_env(list) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (list)
	{
		if (process(array, list, i) == false)
			return (NULL);
		i++;
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}

static bool	process(char **array, t_env *list, int i)
{
	int		leng;

	leng = ft_strlen(list->name) + ft_strlen(list->arg) + 2;
	array[i] = malloc(leng * sizeof(char));
	if (array[i] == NULL)
		return (ft_free_deep(array), false);
	ft_bzero(array[i], leng);
	ft_strlcat(array[i], list->name, leng);
	if (list->is_egal == true)
	{
		ft_strlcat(array[i], "=", leng);
		ft_strlcat(array[i], list->arg, leng);
	}
	return (true);
}
