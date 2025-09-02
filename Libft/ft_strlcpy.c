/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:27:13 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:40:25 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copies src to dest and returns the lenght of src
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

/* int main(void)
{
	char str[] = "Hellu wurld";
	char temp[10];
	unsigned int len;
	
	len = ft_strlcpy(temp, str, 8);
	printf("Str in destiny: '%s'\n", temp);
	printf("Lenght of string in src is: %u\n", len);
} */