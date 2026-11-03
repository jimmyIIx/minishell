/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:04:00 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:07:36 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strlcpy_exp(char *str, char c)
{
	int		i;
	int		y;
	char	*dest;

	i = 0;
	y = 0;
	if (!str)
		return (0);
	dest = malloc(sizeof(char) * ft_strllen(str, '=') + 10);
	while (str[i] != c && str[i])
		i++;
	i++;
	while (str[i])
	{
		dest[y] = str[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
