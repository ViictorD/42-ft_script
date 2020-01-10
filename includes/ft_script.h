/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:08:55 by vdarmaya          #+#    #+#             */
/*   Updated: 2020/01/04 18:08:55 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include "../libft/libft.h"

# define BUFFSIZE	256

// OPT

# define OPT_A		0x1
# define OPT_C		0x2
# define OPT_E		0x4
# define OPT_Q		0x8

// FDS

# define MASTER		0
# define SLAVE		1
# define FILE		2

typedef struct	s_script
{
	int			options;
	char		*cmd;
	char		*filename;
	int			fds[3];
}				t_script;

void	manage(t_script *script, char **env);
char	*get_env_value(char **env, char *name);
void	write_time(char start, t_script *script);

#endif