/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:58:47 by avinals-          #+#    #+#             */
/*   Updated: 2025/03/24 15:33:41 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putu(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_putu(nbr / 10, count);
	}
	ft_putchar((nbr % 10) + '0', count);
}

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
	}
	ft_putchar((nbr % 10) + '0', count);
	return ;
}

void	ft_putnbr_base(unsigned long str, char *base, int *count)
{
	if (str >= 16)
		ft_putnbr_base(str / 16, base, count);
	ft_putchar(base[str % 16], count);
}

void	ft_putp(void *str, int *count)
{
	long int	long_str;

	if (str == NULL)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	long_str = (unsigned long)str;
	ft_putstr("0x", count);
	ft_putnbr_base(long_str, BASE_LOWER, count);
}
