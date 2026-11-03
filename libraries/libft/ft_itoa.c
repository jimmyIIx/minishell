/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:48:14 by nippolit          #+#    #+#             */
/*   Updated: 2024/08/23 15:02:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizelen(int nb)
{
	size_t	i;

	i = 0;
	while (nb / 10)
	{
		nb = nb / 10;
		i++;
	}
	if (nb < 0)
		++i;
	return (++i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	size_t	marge;

	marge = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_sizelen(n);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		marge = 1;
	}
	while (size > marge)
	{
		size--;
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
// convertir nombre en caractere
/*
int main()
{
	printf("teste %s \n", ft_itoa(42));
}
*/
