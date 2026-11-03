/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:19:39 by jimmy             #+#    #+#             */
/*   Updated: 2024/10/11 01:23:07 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_mod(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		result[i + j] = str2[j];
		j++;
	}
	result[i + j] = '\0';
	ft_free(str1);
	return (result);
}
