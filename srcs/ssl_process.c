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

static int	process_file(char **filename, t_arg *arg, t_ssl *ssl)
{
	(void)ssl;
	arg->type = FILE;
	arg->filename = *filename;
	if ((arg->fd = ft_get_fd_read(arg->filename)) == -1)
	{
		ft_putstr_fd("ft_ssl: Cannot open `", 2);
		ft_putstr_fd(arg->filename, 2);
		ft_putendl_fd("'", 2);
		return (1);
	}
	ft_get_raw_input(arg->fd, &(arg->argument));
	ssl->hashfct(arg->argument.content);	
	return (0);
}

/*
** End up here if `s' option is found
*/
static int	process_str(char ***av, t_arg *arg, t_ssl *ssl)
{
	// dprintf(1, "process_str\n");
	**av += 1;
	if (!***av && *(*av + 1))
	{
		*av += 1;
		arg->argument.content = ft_strdup(**av);
		arg->argument.len = ft_strlen(arg->argument.content);
	}
	else if ((***av))
	{
		arg->argument.content = ft_strdup(**av);
		arg->argument.len = ft_strlen(arg->argument.content);
	}
	else
		return (ssl_opt_usage('s', MISS_ARG));
	arg->type = STR;
	ssl->hashfct(arg->argument.content);	
	return (0);
}

int		handle_dash(char *opt, t_ssl *ssl)
{
	ssl->only_file = 1;
	if (*(opt + 1))
	{
		ssl->exit = 1;
		return (ssl_opt_usage('-', ILLEGAL));	
	}
	return (0);
}

static int	process_opt(char ***av, t_arg *arg, t_ssl *ssl)
{
	**av += 1;
	while (***av)
	{
		if (***av == '-')
			return(handle_dash(**av, ssl));
		if (***av == 'q')
			ssl->quiet = 1;
		if (***av == 'r')
			ssl->reverse = 1;
		if (***av == 's')
			return (process_str(av, arg, ssl));
		if (***av)
			**av += 1;
	}
	return (0);
}

static int	process_arg(char ***av, t_ssl *ssl)
{
	t_arg	arg;
	int		ret;

	ret = 0;
	init_ssl_arg(&arg);
	if (**av[0] == '-' && !ssl->only_file)
		process_opt(av, &arg, ssl);
	else
	{
		ssl->only_file = 1;
		process_file(*av, &arg, ssl);
	}
	// debug_arg(&arg);
	clear_ssl_arg(&arg);
	return (ret);
}

void	ssl_main_process(char **av, t_ssl *ssl)
{
	while (*av && (ssl->exit != 1))
	{
		process_arg(&av, ssl);
		if (*av)
			av++;
	}
}
