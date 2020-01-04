/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:58 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:20:10 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i])
	{
		while ((s1[i] == s2[j]) && (i < n))
		{
			i++;
			j++;
			if (!s2[j])
				return ((char *)&s1[i - j]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
