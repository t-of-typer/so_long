/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:56:19 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:00:11 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//adds a new node to the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}

/* int main(void)
{
	t_list *node1 = ft_lstnew("Node 1 (original)");
	t_list *node2 = ft_lstnew("Node 2 (new)");

	ft_lstadd_back(&node1, node2);

	while (node1)
	{
		printf("node: %s\n", (char *)node1->content);
		node1 = node1->next;
	}
	return (0);
} */