/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:07:32 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/04 18:07:32 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/ioctl.h>
#define __USE_XOPEN_EXTENDED
#include "/usr/include/stdlib.h"
#include <fcntl.h>
#include "ft_script.h"

void	help_exit(void **ptr_opt)
{
	if (*ptr_opt)
		ft_memdel(ptr_opt);
	ft_putstr("\nUsage:\n\tscript [options] [file]\n\n");
	ft_putstr("Make a typescript of a terminal session.\n\n");
	ft_putstr("Options:\n");
	ft_putstr("\t-a            append the output\n");
	ft_putstr("\t-c <command>  run command rather than interactive shell\n");
	ft_putstr("\t-e            return exit code of the child process\n");
	ft_putstr("\t-q            be quiet\n");
	ft_putstr("\t-h            display this help\n\n");
	_exit(0);
}

void	get_opt(int ac, char **av, void **ptr_script)
{
	t_script	*script;
	int i;

	script = *ptr_script;
	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-a"))
			script->options = script->options | OPT_A;
		else if (!ft_strcmp(av[i], "-c") && i + 1 < ac)
		{
			script->options = script->options | OPT_C;
			script->cmd = av[++i];
		}
		else if (!ft_strcmp(av[i], "-e"))
			script->options = script->options | OPT_E;
		else if (!ft_strcmp(av[i], "-q"))
			script->options = script->options | OPT_Q;
		else if (!ft_strcmp(av[i], "-h"))
			help_exit(ptr_script);
		else
		{
			script->filename = av[i];
			return ;
		}
		i++;
	}
}

void	open_ptmx(t_script *script)
{
	char	*pts_name;

	if ((script->fds[MASTER] = open("/dev/ptmx", O_RDWR)) < 0)
		ft_exiterror("Can not open /dev/ptmx", 1);
	if (grantpt(script->fds[MASTER]) < 0)			// FORBIDEN
		ft_exiterror("Can not grant pts", 1);
	if (unlockpt(script->fds[MASTER]) < 0)			// FORBIDEN
		ft_exiterror("Can not unlock pts", 1);
	if (!(pts_name = ptsname(script->fds[MASTER])))	// FORBIDEN
		ft_exiterror("Can not get pts name", 1);
	if ((script->fds[SLAVE] = open(pts_name, O_RDWR)) < 0)
		ft_exiterror("Can not open slave fd", 1);
}
	
int		main(int ac, char **av, char **env)
{
	t_script	*script;

	if (!(script = (t_script*)malloc(sizeof(t_script))))
		ft_exiterror("Malloc failed", 1);
	script->options = 0;
	script->cmd = NULL;
	script->filename = NULL;
	get_opt(ac, av, (void*)&script);
	open_ptmx(script);
	manage(script, env);
}