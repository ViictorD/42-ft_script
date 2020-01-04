/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:57:49 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:19:21 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strfind(const char *s, int start, int c)
{
	if (start >= 0)
	{
		while (s[start] && s[start] != c)
			++start;
	}
	return (start);
}
