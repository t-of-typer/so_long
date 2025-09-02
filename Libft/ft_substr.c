/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:53:35 by avinals           #+#    #+#             */
/*   Updated: 2025/02/06 18:46:15 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//creates a substring from s and stores it in a new ptr
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	ptr = malloc(len + 1);
	if (ptr == NULL || s == NULL)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

/* int main(void)
{
	char *s = "String to duplicate";
	char *ptr; // place in memory to store the dup string

	ptr = ft_substr(s, 5, 10);
	if (ptr == NULL) 
	{
		printf("Allocation failed\n");
		return (0);
	}
	printf("%s\n", ptr);
	free(ptr);
	return (0);
} */