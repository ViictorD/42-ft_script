/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:24:56 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/28 20:47:40 by vdarmaya         ###   ########.fr       */
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
			ft_putstr("Script started, file is ");
		else
			ft_putstr("Script done, file is ");
		ft_putendl(script->filename);
	}
	gettimeofday(&now, NULL);
	if (start)
		ft_fputstr("Script started on ", script->fds[FILE]);
	else
		ft_fputstr("\nScript done on ", script->fds[FILE]);
	ft_fputstr(ctime(&(now.tv_sec)), script->fds[FILE]);
}


void	term_init(t_script *script)
{
	struct termios	term_old;

	if (tcgetattr(0, &term_old) < 0/*ioctl(0, TIOCGETA, &term_old)*/)	// FORBIDEN
		ft_exiterror("Can't get termios struct", 1);
	ft_memcpy(&script->term, &term_old, sizeof(struct termios));
	term_old.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR |
		IGNCR | ICRNL | IXON);
	term_old.c_oflag &= ~OPOST;
	term_old.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	term_old.c_cflag &= ~(CSIZE | PARENB);
	term_old.c_cflag |= CS8;
	term_old.c_cc[VMIN] = 1;
	term_old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term_old) < 0 /* ioctl(0, TIOCSETAW, &tmp) */)	// FORBIDEN
		ft_exiterror("Can't set termios struct", 1);
}
void	restore_term(t_script *script)
{
	if (tcsetattr(0, TCSADRAIN, &script->term) < 0 /* ioctl(0, TIOCSETAW, &tmp) */)	// FORBIDEN
		ft_exiterror("Can't set termios struct", 1);
}