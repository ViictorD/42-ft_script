/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelpp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:50:56 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/04 17:19:01 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "io.h"

void	ft_strdelpp(char ***str)
{
	int		i;
	char	**tmp;

	tmp = *str;
	i = -1;
	while (tmp[++i])
		ft_strdel(&(tmp[i]));
	free(*str);
	*str = NULL;
}
