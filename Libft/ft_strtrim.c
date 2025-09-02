/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:07:58 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:47:31 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//removes set from the beginning and end of s1 and stores it in a new ptr
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && (ft_strchr(set, *s1)))
	{
		s1++;
		len--;
	}
	while (len > 0 && (ft_strchr(set, s1[len - 1])))
		len--;
	ptr = ft_substr(s1, 0, len);
	return (ptr);
}

/* int main(void)
{
	char *s1 = "  \tString to trim  \t";
	char *set = " \t";

	printf("%s\n", ft_strtrim(s1, set));
	
	free(ft_strtrim(s1, set));
	return (0);
} */