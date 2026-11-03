/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:26:38 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/14 16:58:17 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if ((nmemb * size >= 65535) || (nmemb >= 65535 && size >= 65535))
		return (NULL);
	res = (void *)malloc(nmemb * size);
	if (res == NULL)
	{
		return (NULL);
	}
	ft_bzero(res, nmemb * size);
	return (res);
}
// alloue la mémoire pour un tableau de "nmemb" éléments de "size" octets
