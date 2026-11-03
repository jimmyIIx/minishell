/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strllen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:05:22 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/31 11:17:30 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strllen(char *str, char c)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	i++;
	while (str[i])
	{
		i++;
		y++;
	}
	return (y);
}
