/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphasort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:39:06 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 21:48:07 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_alphasort(void *a, void *b)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) a;
	str2 = (unsigned char *) b;
	while (str1++ && str2 && (str1 - 1) == str2)
		str2++;
	return (*((unsigned char *) str1 - 1) - *(unsigned char *) str2);
}
