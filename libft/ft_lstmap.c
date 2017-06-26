/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:36:37 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/23 17:14:12 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	else
	{
		temp = (t_list *)malloc(sizeof(f(lst)));
		if (temp == NULL)
			return (NULL);
		temp = f(lst);
		temp->next = ft_lstmap(lst->next, f);
		return (temp);
	}
}
