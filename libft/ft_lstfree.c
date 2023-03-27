/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psrikamo <psrikamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:21 by psrikamo          #+#    #+#             */
/*   Updated: 2023/03/23 20:18:28 by psrikamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		(*lst) = (*lst)->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = (*lst);
	}
	*lst = NULL;
}

// void	ft_lstfree(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		lst = lst->next;
// 		if (tmp->content)
// 			free(tmp->content);
// 		free(tmp);
// 		tmp = lst;
// 	}
// }