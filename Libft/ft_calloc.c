/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:52:50 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:45:23 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//mallocs and initializes mem to 0
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int main(void)
{
	int *ptr;
	size_t nmemb = 2;
	size_t size = sizeof(int);

	ptr = ft_calloc(nmemb, size);
	if (ptr == NULL)
	{
		printf("Error allocating\n");
		return (0);
	}
	size_t i = 0;
	while (i < nmemb)
	{
		printf("%d\n", ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
} */