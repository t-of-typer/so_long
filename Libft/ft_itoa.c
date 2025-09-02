/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:44 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:05:05 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//strlen but for integers (for malloc in itoa)
static int	ft_numlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

//does the conversion from int to string
static void	ft_iconvert(int nb, char *str, int len)
{
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
}

//calls conversion, checks for errors and returns the string
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		ft_memcpy(str, "-2147483648", 12);
		return (str);
	}
	ft_iconvert(n, str, len);
	return (str);
}

/* int main(void)
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return (0);
} */