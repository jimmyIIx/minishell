/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:51:12 by nippolit          #+#    #+#             */
/*   Updated: 2024/09/06 15:39:48 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*cleanus(char **cln)
{
	int	i;

	i = 0;
	while (cln[i])
	{
		free(cln[i++]);
	}
	free(cln);
	return (NULL);
}

static size_t	nbr_words(char const *str, char c)
{
	size_t	taille_words;
	size_t	i;

	taille_words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			taille_words++;
		i++;
	}
	return (taille_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tab;
	size_t	i;
	size_t	y;
	size_t	start;

	i = 0;
	y = 0;
	words = nbr_words(s, c);
	tab = ft_calloc((words + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (i < words)
	{
		while (s[y] == c && s[y] != '\0')
			y++;
		start = y;
		while (s[y] != c && s[y] != '\0')
			y++;
		tab[i] = ft_substr(s, start, (y - start));
		if (!tab[i])
			return (cleanus(tab));
		i++;
	}
	return (tab);
}
//diviser une chaîne fonction d'un délimiteur spécifié
