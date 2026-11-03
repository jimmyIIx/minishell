/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:28:48 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/06 22:07:31 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	target;

	i = 0;
	target = ft_strlen(s2);
	if (!s1)
		return (NULL);
	if (!s2 || target == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
			j++;
		if (j == target)
			return ((char *) s1 + i);
		i++;
	}
	return (NULL);
}
// Trouver la première occurrence d'une sous-chaîne dans une chaîne principale
