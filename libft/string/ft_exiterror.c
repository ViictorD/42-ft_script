/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exiterror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:57 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:18:21 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "string.h"

void	ft_exiterror(const char *str, int status)
{
	ft_fputendl(str, 2);
	exit(status);
}
