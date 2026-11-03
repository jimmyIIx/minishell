/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:23 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/20 18:24:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
	else
	{
		while (n)
		{
			--n;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
		return (dest);
	}
}
// Copier un bloc de mémoire d'une source vers une destination
/*
 Fonctionne même si les zones source et destination se chevauchent.
 trois arguments : 
                   - un pointeur vers destination (*dst), 
				   - un pointeur vers la source (*src),
				   - le nombre d'octets à remplir (n).
*/
