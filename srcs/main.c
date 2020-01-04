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
}

void	get_opt(int ac, char **av, void **ptr_opt)
{
	t_opt	*opt;
	int i;

	opt = *ptr_opt;
	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-a"))
			opt->a = 1;
		else if (!ft_strcmp(av[i], "-c") && i + 1 < ac)
		{
			opt->c = 1;
			opt->cmd = av[++i];
		}
		else if (!ft_strcmp(av[i], "-e"))
			opt->e = 1;
		else if (!ft_strcmp(av[i], "-q"))
			opt->q = 1;
		else if (!ft_strcmp(av[i], "-h"))
			help_exit(ptr_opt);
		else
		{
			opt->filename = av[i];
			return ;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_opt	*opt;

	if (!(opt = (t_opt*)malloc(sizeof(t_opt))))
		ft_exiterror("Malloc failed", 1);
	opt->a = 0;
	opt->c = 0;
	opt->cmd = NULL;
	opt->e = 0;
	opt->q = 0;
	opt->h = 0;
	opt->filename = NULL;
	get_opt(ac, av, (void*)&opt);
	// execute <--- TODO
}