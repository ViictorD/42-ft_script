/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:07:01 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/10 20:49:05 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "ft_script.h"

void	manage_child(t_script *script, char **env)
{
	char	*shell_path;
	char	*shell_arg[3];
	int		ret;

	close(script->fds[MASTER]);
	shell_path = get_env_value(env, "SHELL");
	if (shell_path == NULL)
		shell_path = "/bin/bash";
	dup2(script->fds[SLAVE], 0);
	dup2(script->fds[SLAVE], 1);
	dup2(script->fds[SLAVE], 2);
	close(script->fds[SLAVE]);
	setsid();
	ioctl(0, TIOCSCTTY, 1);
	shell_arg[0] = shell_path;
	shell_arg[1] = "-i";
	shell_arg[2] = NULL;
	ret = execve(shell_path, shell_arg, env);
	_exit(ret);

}

void	manage_parent(t_script *script)
{
	fd_set		readfds;
	int			tmp;
	char		buffer[BUFFSIZE];

	FD_ZERO(&readfds);
	write_time(1, script);
	while (1)
	{
		FD_SET(0, &readfds);
		FD_SET(script->fds[MASTER], &readfds);
		if (select(script->fds[MASTER] + 1, &readfds, NULL, NULL, NULL) < 0)
			break ;
		if (FD_ISSET(0, &readfds))
		{
			if ((tmp = read(0, buffer, BUFFSIZE)) <= 0)
				break ;
			write(script->fds[MASTER], buffer, tmp);
		}
		if (FD_ISSET(script->fds[MASTER], &readfds))
		{
			if ((tmp = read(script->fds[MASTER], buffer, BUFFSIZE)) <= 0)
				break ;
			write(1, buffer, tmp);
			write(script->fds[FILE], buffer, tmp);
		}
	}
	write_time(0, script);
}

void	open_output_file(t_script *script)
{
	if ((script->fds[FILE] = open("./typescript2", O_RDWR | O_TRUNC)) == -1)
		ft_exiterror("Could not open log file", 1);
}

void	manage(t_script *script, char **env)
{
	pid_t	pid;

	if ((pid = fork()) == -1)
		ft_exiterror("Fork failed", 1);
	if (pid == 0)
		manage_child(script, env);
	else
	{
		close(script->fds[SLAVE]);
		open_output_file(script);
		manage_parent(script);
		close(script->fds[MASTER]);
		close(script->fds[FILE]);
	}
}