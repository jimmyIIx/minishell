/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:30:18 by nippolit          #+#    #+#             */
/*   Updated: 2025/01/21 22:18:36 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_mod_gnl(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

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
	free (str1);
	free (str2);
	return (result);
}

char	*initline(void)
{
	char	*line;

	line = malloc(1);
	if (line)
		line[0] = '\0';
	return (line);
}

int	verif(char *line, int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (line != NULL)
			free(line);
		return (1);
	}
	if (!line)
		return (1);
	return (0);
}
