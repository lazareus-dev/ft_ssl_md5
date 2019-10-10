/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_usage.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:02:36 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 11:02:37 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	std_cmds(void)
{
	ft_putendl_fd("Standard commands:", 2);
	ft_putchar_fd('\n', 2);
}

static void	md_cmds(void)
{
	ft_putendl_fd("Message Digest commands:", 2);
	ft_putendl_fd("md5", 2);
	ft_putendl_fd("sha256", 2);
	ft_putchar_fd('\n', 2);
}

static void	cipher_cmds(void)
{
	ft_putendl_fd("Cipher commands:", 2);
	ft_putchar_fd('\n', 2);
}

int			usage_invalid_cmd(char *cmd)
{
	ft_putstr_fd("ft_ssl: Error: '", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd("' is an invalid command.\n", 2);
	std_cmds();
	md_cmds();
	cipher_cmds();
	return (1);
}

int			ssl_opt_usage(char c)
{
	ft_putstr_fd("md5: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ft_ssl command [-pqr] [-s string] [files ...]", 2);
	return (1);
}

int			ssl_usage(void)
{
	ft_putendl_fd("usage: ft_ssl command [command opts] [command args]", 2);
	return (1);
}
