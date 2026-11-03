/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ritoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:46:42 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/18 20:59:10 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count(int n)
{
	int	i;

	i = 2;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_ritoa(int n)
{
	long	i;
	int		longueur;
	char	*str;

	i = n;
	if (n == -2147483648)
		return (ft_rstrdup("-2147483648"));
	longueur = count(n);
	str = malloc(sizeof(char) * longueur);
	if (!str)
		return (NULL);
	if (n < 0)
		n = n * (-1);
	str[--longueur] = '\0';
	while ((--longueur) >= 0)
	{
		str[longueur] = n % 10 + '0';
		n = n / 10;
	}
	if (i < 0)
		*str = '-';
	return (str);
}
