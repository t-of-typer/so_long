/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinals- <avinals-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:50:37 by avinals-          #+#    #+#             */
/*   Updated: 2025/02/06 19:02:35 by avinals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//applies f to the content of each node and stores it in new list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del)
				del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* // Wrapper function for ft_strdup
void *ft_strdup_wrapper(void *content)
{
    return ft_strdup((char *)content);
}

// Wrapper function for ft_putstr_fd
void ft_putstr_wrapper(void *content)
{
    ft_putstr_fd((char *)content, 1);
}

int main(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    ft_lstadd_front(&node1, node2);
    ft_lstadd_front(&node1, node3);

    t_list *new_lst = ft_lstmap(node1, ft_strdup_wrapper, free);
    if (!new_lst)
    {
        // Handle allocation failure
        ft_lstclear(&node1, free);
        return (1);
    }

    ft_lstiter(new_lst, ft_putstr_wrapper);

    printf("\nClearing original list\n");
    ft_lstclear(&node1, NULL); // Og lst contents not dynamically allocated

    printf("Clearing new list\n");
    ft_lstclear(&new_lst, free); // New lst contents dynamically allocated

    printf("Finished\n");
    return (0);
} */