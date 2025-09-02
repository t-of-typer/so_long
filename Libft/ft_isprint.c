/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:27:22 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 18:37:49 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//checks if c is printable
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* int main(void)
{
    char c = '\a'; 
    
    if (ft_isprint(c))
        printf("Char is %c\n", c);
    else
         printf("Char cannot be printed\n");
} */