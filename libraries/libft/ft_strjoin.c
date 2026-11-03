/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:21:51 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/14 16:58:09 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*result;
	int		i;
	int		j;

	if (!str1 && !str2)
		return (ft_strdup(""));
	else if (str1 && !str2)
		result = malloc((ft_strlen(str1) + 1) * sizeof(char));
	if (str2 && !str1)
		result = malloc((ft_strlen(str2) + 1) * sizeof(char));
	else
		result = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (str1 && str1[++i])
		result[i] = str1[i];
	while (str2 && str2[++j])
		result[i + j] = str2[j];
	result[i + j] = '\0';
	return (result);
}
// Concaténer plusieurs chaînes de caractères en une seule
