/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:38 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 16:41:45 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
// Dupliquer une chaîne de caractères
