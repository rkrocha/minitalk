/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:17:47 by rkochhan          #+#    #+#             */
/*   Updated: 2020/02/02 15:03:48 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*tracker;

	if (!lst)
		return ;
	tracker = *lst;
	while (tracker != NULL)
	{
		temp = tracker->next;
		del(tracker->content);
		free(tracker);
		tracker = temp;
	}
	*lst = NULL;
}
