/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_end_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:56 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:16:55 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_go_end_list(t_list *node)
{
	if (node)
	{
		while (node->next)
			node = node->next;
		return (node);
	}
	return (NULL);
}
