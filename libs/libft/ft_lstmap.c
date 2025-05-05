/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:38:56 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 18:38:56 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*next;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	root = 0;
	next = 0;
	while (lst)
	{
		content = f(lst->content);
		next = ft_lstnew(content);
		if (!next)
		{
			(*del)(content);
			ft_lstclear(&root, del);
			return (0);
		}
		ft_lstadd_back(&root, next);
		lst = lst->next;
	}
	return (root);
}
