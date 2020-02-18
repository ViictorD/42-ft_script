/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:42:09 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/02/18 15:02:37 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <termios.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

# define BUFFSIZE		256

# define OPT_A			0x1
# define OPT_C			0x2
# define OPT_E			0x4
# define OPT_Q			0x8

# define MASTER			0
# define SLAVE			1
# define FILE			2

typedef struct			s_script
{
	int					options;
	char				*cmd;
	char				*filename;
	struct termios		term;
	int					fds[3];
	int					ret_value;
	struct winsize		win;
}						t_script;

void					manage(t_script *script, char **env);
char					*get_env_value(char **env, char *name);
void					write_time(char start, t_script *script);
void					term_init(t_script *script);
void					restore_term(t_script *script);

#endif
