/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 10:16:08 by rkochhan          #+#    #+#             */
/*   Updated: 2020/02/02 15:02:13 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tracker;

	tracker = *lst;
	if (tracker)
	{
		while (tracker->next != NULL)
			tracker = tracker->next;
		tracker->next = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
