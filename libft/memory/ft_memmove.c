/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:57 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:18:01 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpybis(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = dest;
	src2 = src;
	while (n--)
		*dest2++ = *src2++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;

	tmp = malloc(n);
	ft_memcpybis(tmp, src, n);
	ft_memcpybis(dest, tmp, n);
	free(tmp);
	return (dest);
}
