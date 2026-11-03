/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:53 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 16:43:43 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
		{
			return ((char *) s + i);
		}
		i--;
	}
	return (NULL);
}
// Rechercher la dermiere occurrence d'un caractère dans une chaine
