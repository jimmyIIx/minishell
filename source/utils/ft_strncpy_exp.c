/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:36:56 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:06:11 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strncpy_exp(char *str, char c)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
		return (0);
	dest = malloc(sizeof(char) * ft_strnlen(str, '=') + 1);
	while (str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
