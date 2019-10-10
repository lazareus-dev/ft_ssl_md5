/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:02:12 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 11:02:15 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/ft_printf/ft_printf.h"

# define MD5 0
# define SHA256 1

typedef struct		s_args
{
	char			*filename;
	int				opts;
	struct s_args	*prev;
	struct s_args	*next;
}					t_args;

typedef struct		s_ssl
{
	t_headlst		args_lst;
	t_mem			std_in;
	short			cmd;
}					t_ssl;

int					ssl_usage(void);
int					usage_invalid_cmd(char *cmd);

#endif
