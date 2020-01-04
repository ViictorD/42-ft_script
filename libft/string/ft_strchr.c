/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:57 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:18:38 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *s, int c)
{
	char		find;
	char		*fnd;
	int			ct;

	find = c;
	fnd = NULL;
	ct = 0;
	if (s)
	{
		while (s[ct] != '\0' && fnd == NULL)
		{
			if (s[ct] == find)
				fnd = (char *)(s + ct);
			ct++;
		}
		if (s[ct] == find && fnd == NULL)
			fnd = (char *)(s + ct);
	}
	return (fnd);
}
