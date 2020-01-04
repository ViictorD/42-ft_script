/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:58 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:20:03 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	eq;

	if (s1 && s2)
	{
		eq = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
		return (eq);
	}
	return (0);
}
