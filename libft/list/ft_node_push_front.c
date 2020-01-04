/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:56 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:17:18 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_node_push_front(t_list **begin_list, void *data)
{
	t_list	*new_node;

	if (begin_list)
	{
		if (*begin_list)
		{
			new_node = ft_create_node(data);
			new_node->next = *begin_list;
			(*begin_list)->prev = new_node;
			*begin_list = new_node;
		}
		else
			*begin_list = ft_create_node(data);
	}
	return ;
}
