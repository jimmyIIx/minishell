/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:27:43 by nippolit          #+#    #+#             */
/*   Updated: 2024/05/13 16:46:58 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;
	size_t	j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (NULL);
	while (s[++i])
	{
		if ((size_t) i >= start && j < len)
			res[j++] = s[i];
	}
	res[j] = '\0';
	return (res);
}
// Renvoie une sous-chaîne indiquée d'une chaîne de caractères.
