/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:28:10 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/13 18:48:39 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
// La fonction renvoie la longueur de la chaîne source
/*
 trois arguments :
                   - un pointeur vers destination (*dst),
				   - un pointeur vers la source (*src),
				   - le nombre d'octets à remplir (size).
*/
