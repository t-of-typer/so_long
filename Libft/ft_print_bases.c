/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:01:32 by avinals-          #+#    #+#             */
/*   Updated: 2025/03/24 15:02:03 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlower(unsigned int nbr, int *count)
{
	ft_putnbr_base(nbr, BASE_LOWER, count);
}

void	ft_putupper(unsigned int nbr, int *count)
{
	ft_putnbr_base(nbr, BASE_UPPER, count);
}
