/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:29:27 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:39:14 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//sets n bytes of s to 0
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/* int main(void)
{
    char str[50] = "String to be modified";

    printf("Str w/o bzero: %s\n", str);
    ft_bzero(str, 3);
    printf("Str w bzero (null): %s\n", str);
	return (0);
} */