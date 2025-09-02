/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:05:55 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:39:44 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies n bytes from src to dest without overlap
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	if (s < d)
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
		return (dest);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char src[50] = "Source string";
	char dest[50];

	printf("Without memmove:\n");
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);

	ft_memmove(dest, src, 25);

	printf("With memmove:\n");
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);

	return (0);
} */