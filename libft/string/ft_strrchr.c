/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:32:58 by bdurst            #+#    #+#             */
/*   Updated: 2020/01/04 17:20:13 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strrchr(const char *s, int c)
{
	char		find;
	char		*fnd;
	int			ct;

	find = c;
	fnd = NULL;
	ct = 0;
	while (s[ct] != '\0')
	{
		if (s[ct] == find)
			fnd = (char *)(s + ct);
		ct++;
	}
	if (s[ct] == find)
		fnd = (char *)(s + ct);
	return (fnd);
}
