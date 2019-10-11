/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_arg.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:45:08 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 17:45:09 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init_ssl_arg(t_arg *arg)
{
	arg->type = -1;
	arg->filename = NULL;
	arg->fd = -1;
	arg->argument.content = NULL;
	arg->argument.len = 0;
}

void	clear_ssl_arg(t_arg *arg)
{
	ft_memdel(&(arg->argument.content));
	close(arg->fd);
}