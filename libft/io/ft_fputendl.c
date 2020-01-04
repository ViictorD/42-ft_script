/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:55 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:36:14 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	ft_fputendl(char const *s, int fd)
{
	int ret;

	ret = write(fd, s, ft_strlen(s));
	ret = write(fd, "\n", 1);
	ret = ret;
}
