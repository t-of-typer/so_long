/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:50:05 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:00:39 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//strlen for linked lists (counts the nodes)
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = lst;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

/* int main(void)
{
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);

	printf("List size: %d\n", ft_lstsize(node1));
	return (0);
} */