/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_hashing.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 11:08:39 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 11:08:40 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int	ssl_hashing(t_arg *arg, t_ssl *ssl)
{
	if (!ssl->quiet && arg->type == FILE)
		ft_printf("MD5 (%s) = ", arg->filename);
	else if (!ssl->quiet && arg->type == STR)
		ft_printf("MD5 (\"%s\") = ", arg->argument.content);
	ssl->hashfct(arg->argument.content, arg->argument.len);
	ft_printf("\n");
	return (0);
}
