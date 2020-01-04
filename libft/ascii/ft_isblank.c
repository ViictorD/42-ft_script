/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:01:40 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:15:26 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

int	ft_isblank(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}
