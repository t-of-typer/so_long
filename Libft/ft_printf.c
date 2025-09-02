/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:41 by avinals           #+#    #+#             */
/*   Updated: 2025/03/25 13:14:49 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* formats to check: c s p d i u x X % */
int	check_format(va_list list, char str, int *count)
{
	if (str == 'c')
		ft_putchar(va_arg(list, int), count);
	else if (str == 's')
		ft_putstr(va_arg(list, char *), count);
	else if (str == 'p')
		ft_putp(va_arg(list, void *), count);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(list, int), count);
	else if (str == 'u')
		ft_putu(va_arg(list, unsigned int), count);
	else if (str == 'x')
		ft_putlower(va_arg(list, unsigned int), count);
	else if (str == 'X')
		ft_putupper(va_arg(list, unsigned int), count);
	else if (str == '%')
		ft_putchar('%', count);
	return (*count);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		count;

	count = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			check_format(list, *str, &count);
			str++;
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}
