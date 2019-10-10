/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:02:25 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 11:02:27 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include <unistd.h>

int		ssl_get_cmd(t_ssl *ssl, char *cmd)
{
	if (ft_strequ(cmd, "md5"))
		ssl->hashfct = ssl_md5;
	else if (ft_strequ(cmd, "sha256"))
		ssl->hashfct = ssl_sha256;
	else
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_ssl ssl;

	(void)av;
	if (ac == 1)
		return (ssl_usage());
	if (ssl_get_cmd(&ssl, av[1]) == -1)
		return (usage_invalid_cmd(av[1]));
	
	return (0);
}
