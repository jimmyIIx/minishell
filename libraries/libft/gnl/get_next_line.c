/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:30:26 by nippolit          #+#    #+#             */
/*   Updated: 2025/01/21 22:18:46 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mouv(char *stock, int i);
char	*stocking(char *stock, int *i);

char	*get_next_line(int fd)
{
	static char	stock[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			read_amount;

	line = initline();
	if (verif(line, fd) == 1)
		return (NULL);
	while (1)
	{
		line = ft_strjoin_mod_gnl(line, stocking(stock[fd], &i));
		if (i > 0 && stock[fd][i - 1] == '\n')
			return (mouv(stock[fd], i), line);
		read_amount = read(fd, stock[fd], BUFFER_SIZE);
		if (read_amount == 0 && ft_strlen(line))
		{
			stock[fd][0] = '\0';
			return (line);
		}
		if (read_amount < 1)
			break ;
		stock[fd][read_amount] = '\0';
	}
	free (line);
	return (NULL);
}

void	mouv(char *stock, int i)
{
	ft_memmove(stock, &stock[i], ft_strlen(&stock[i]) + 1);
}

char	*stocking(char *stock, int *i)
{
	char	*temp;

	temp = malloc((ft_strlen(stock) + 1) * sizeof(char));
	*i = 0;
	while (stock[*i] && stock[*i - 1] != '\n')
	{
		temp[*i] = stock[*i];
		(*i)++;
	}
	temp[*i] = '\0';
	return (temp);
}
