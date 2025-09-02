/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:51:20 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:43:38 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds c in n bytes of s
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;
	size_t			i;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)&ptr[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	const char str[] = "String to be searched";
	int c = 'i'; // character to find
	size_t n = 10; // characters to compare

	printf("%s\n", (char *)ft_memchr(str, c, n));
	printf("%s\n", (char *)memchr(str, c, n));
	return (0);
} */
