/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:50:55 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:57:00 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//writes c in the file descriptor given
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* int	main(void)
{
	ft_putchar_fd('a', 1); // 1 is the fd for standard output
} */