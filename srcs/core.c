/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:07:01 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/28 20:43:32 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "ft_script.h"

static void	manage_child(t_script *script, char **env)
{
	char	*shell_path;
	char	*shell_arg[4];

	close(script->fds[MASTER]);
	close(script->fds[FILE]);
	shell_path = get_env_value(env, "SHELL");
	if (shell_path == NULL)
		shell_path = "/bin/bash";
	dup2(script->fds[SLAVE], 0);
	dup2(script->fds[SLAVE], 1);
	dup2(script->fds[SLAVE], 2);
	close(script->fds[SLAVE]);
	setsid();
	ioctl(0, TIOCSCTTY, 1);
	if (access(shell_path, R_OK | X_OK) < 0)
		ft_exiterror("Shell path not found or can't be executed", 1);
	shell_arg[0] = shell_path;
	shell_arg[1] = script->options & OPT_C ? "-c" : "-i";
	shell_arg[2] = script->options & OPT_C ? script->cmd : NULL;
	shell_arg[3] = NULL;
	_exit(execve(shell_path, shell_arg, env));
}

static void	check_resize(t_script *script)
{
	struct winsize	tmp_win;

	if (ioctl(0, TIOCGWINSZ, &tmp_win) != 0)
		ft_exiterror("Can't get the window size", 1);
	if (ft_memcmp(&tmp_win, &(script->win), sizeof(struct winsize)) != 0)
	{
		script->win = tmp_win;
		if (ioctl(script->fds[MASTER], TIOCSWINSZ, &(script->win)) != 0)
			ft_exiterror("Can't set the window size", 1);
	}
}

static void	manage_parent(t_script *script, int tmp)
{
	fd_set		readfds;
	char		buffer[BUFFSIZE];

	FD_ZERO(&readfds);
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
			(tmp >= 1 && buffer[0] == '\r') ? check_resize(script) : NULL;
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
}

void		manage(t_script *script, char **env)
{
	pid_t	pid;
	int		ret;

	write_time(1, script);
	term_init(script);
	if ((pid = fork()) == -1)
		ft_exiterror("Fork failed", 1);
	if (pid == 0)
		manage_child(script, env);
	close(script->fds[SLAVE]);
	manage_parent(script, 0);
	restore_term(script);
	write_time(0, script);
	if (script->options & OPT_E)
	{
		waitpid(pid, &ret, WNOHANG);
		if (WIFEXITED(ret))
			script->ret_value = WEXITSTATUS(ret);
	}
	close(script->fds[MASTER]);
	close(script->fds[FILE]);
}
