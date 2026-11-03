/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:42:53 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 13:58:46 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			return ((char *) s + i);
		}
		i++;
	}
	return (NULL);
}
// Rechercher la première occurrence d'un caractère dans une chaine
