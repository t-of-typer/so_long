/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:58 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:02:07 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//applies f to the content of each node
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* // Wrapper function to match the expected signature
void ft_putstr_wrapper(void *content)
{
    ft_putstr_fd((char *)content, 1);
}

int main(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");

    ft_lstadd_front(&node1, node2);

    // Use the wrapper function with ft_lstiter
    ft_lstiter(node1, ft_putstr_wrapper);

    return 0;
} */