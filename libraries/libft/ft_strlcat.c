/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:42 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/13 18:48:09 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	while (dest[i])
	{
		i++;
	}
	while (src[j] && (j + i + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (j < size)
	{
		dest[i + j] = '\0';
	}
	if (size < len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + len);
}
// La fonction renvoie la longueur totale de la chaîne
/*
trois arguments :
                   - un pointeur vers destination (*dst),
				   - un pointeur vers la source (*src),
				   - le nombre d'octets à remplir (size).
*/
