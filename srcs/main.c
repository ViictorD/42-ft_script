/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:07:32 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/02/18 15:55:42 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "ft_script.h"

static void	help_exit(void)
{
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

static void	get_opt(int ac, char **av, t_script *script)
{
	int	i;

	i = 0;
	while (++i < ac)
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
			help_exit();
		else
		{
			script->filename = av[i];
			return ;
		}
	}
}

static void	open_ptmx(t_script *script)
{
	char	pts_name[128];

	if (ioctl(0, TIOCGWINSZ, &(script->win)) != 0)
		ft_exiterror("Can't get the window size", 1);
	if ((script->fds[MASTER] = open("/dev/ptmx", O_RDWR)) < 0)
		ft_exiterror("Can not open /dev/ptmx", 1);
	if (ioctl(script->fds[MASTER], TIOCPTYGRANT) < 0)
		ft_exiterror("Can not grant pts", 1);
	if (ioctl(script->fds[MASTER], TIOCPTYUNLK) < 0)
		ft_exiterror("Can not unlock pts", 1);
	if (ioctl(script->fds[MASTER], TIOCPTYGNAME, pts_name) < 0)
		ft_exiterror("Can not get pts name", 1);
	if ((script->fds[SLAVE] = open(pts_name, O_RDWR)) < 0)
		ft_exiterror("Can not open slave fd", 1);
	if (ioctl(script->fds[MASTER], TIOCSWINSZ, &(script->win)) != 0)
		ft_exiterror("Can't set the window size", 1);
}

int			main(int ac, char **av, char **env)
{
	t_script	*script;

	if (!(script = (t_script*)malloc(sizeof(t_script))))
		ft_exiterror("Malloc failed", 1);
	script->options = 0;
	script->cmd = NULL;
	script->filename = "typescript";
	script->ret_value = 0;
	get_opt(ac, av, script);
	if ((script->fds[FILE] = open(script->filename, (script->options & OPT_A) ?
		(O_WRONLY | O_CREAT | O_APPEND) : (O_WRONLY | O_CREAT | O_TRUNC),
		(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH))) == -1)
		ft_exiterror("Could not open log file", 1);
	open_ptmx(script);
	manage(script, env);
	return (script->ret_value);
}
