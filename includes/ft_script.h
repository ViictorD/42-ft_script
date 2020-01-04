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

typedef struct	s_opt
{
	char		a;
	char		c;
	char		*cmd;
	char		e;
	char		q;
	char		h;
	char		*filename;
}				t_opt;

#endif