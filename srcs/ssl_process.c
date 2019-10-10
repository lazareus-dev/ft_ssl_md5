/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_process.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:44:12 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 17:44:16 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include <stdio.h>

static int	process_str(char **av, t_arg *arg)
{
	// dprintf(1, "process_str\n");
	arg->arg_type = STR;
	if (*(*av + 1) == '\0')
	{
		av++;
		arg->argument.content = ft_strdup(*av);
		return (1);
	}
	else
		arg->argument.content = ft_strdup((*av + 1));
	return (0);
}

static int	process_opt(char **av, t_arg *arg, t_ssl *ssl)
{
	// dprintf(1, "process_opt\n");
	int	ret;

	ret = 0;
	while (**av)
	{
		if (**av == '-')
			ssl->only_file = 1;
		if (**av == 's')
			ret = process_str(av, arg);
		if (**av)
			*av += 1;
	}
	return (ret);
}

static int	process_arg(char **av, t_ssl *ssl)
{
	// dprintf(1, "process_arg\n");
	t_arg	arg;
	int		ret;

	ret = 0;
	init_ssl_arg(&arg);
	if (*av[0] == '-' && !ssl->only_file)
		ret =process_opt(av, &arg, ssl);
	// dprintf(1, "%s\n", arg.argument.content);
	clear_ssl_arg(&arg);
	return (ret);
}

void	ssl_main_process(char **av, t_ssl *ssl)
{
	// dprintf(1, "ssl_main_process\n");
	while (*av)
	{
		dprintf(1, "current av = [%s]\n", *av);
		av += process_arg(av, ssl);
		if (*av)
		av++;
	}
}
