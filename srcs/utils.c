/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:24:56 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/10 20:33:33 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/time.h>
#include "ft_script.h"

char	*get_env_value(char **env, char *name)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(name, env[i], ft_strlen(name)))
			return (ft_strchr(env[i], '=') + 1);
		++i;
	}
	return (NULL);
}

void	write_time(char start, t_script *script)
{
	struct timeval	now;

	if (!(script->options & OPT_Q))
	{
		if (start)
			ft_putstr("Script started, file is typescript2\n");
		else
			ft_putstr("Script done, file is typescript2\n");
	}
	gettimeofday(&now, NULL);
	if (start)
		ft_fputstr("Script started on ", script->fds[FILE]);
	else
		ft_fputstr("Script done on ", script->fds[FILE]);
	ft_fputstr(ctime(&(now.tv_sec)), script->fds[FILE]);
}