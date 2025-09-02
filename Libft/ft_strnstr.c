/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:48:51 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:44:46 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds little in len bytes of big
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] == little[j])
			&& (little[j] != '\0') && ((i + j) < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	const char *big = "String to be searched";
	const char *little = "to be";
	size_t len = 17; // characters to compare

	printf("%s\n", ft_strnstr(big, little, len));
	return (0);
} */