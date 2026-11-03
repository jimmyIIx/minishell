/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:27 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 13:15:44 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}
// remplir un bloc de mémoire avec une valeur spécifiée
/*
 trois arguments : 
                   - un pointeur vers le bloc de mémoire à remplir (*s), 
				   - la valeur avec laquelle remplir le bloc (c),
				   - le nombre d'octets à remplir (n).
*/
