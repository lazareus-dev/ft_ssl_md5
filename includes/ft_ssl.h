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

# define STDIN	0
# define FILE	1
# define STR	2

# define MISS_ARG	0
# define ILLEGAL	1

typedef struct		s_arg
{
	short			type;
	char			*filename;
	int				fd;
	t_mem			argument;
}					t_arg;

/*
** Main struct
*/
typedef struct		s_ssl
{
	t_mem			std_in;
	short			reverse;
	short			quiet;
	short			only_file;
	uint8_t			*(*hashfct)(uint8_t *input, size_t size);
	int				ret;
	int				exit;
}					t_ssl;

/*
** Usages functions
*/
int					ssl_usage(void);
int					usage_invalid_cmd(char *cmd);
int					ssl_opt_usage(char c, int type);

/*
** Hash
*/
int					ssl_hashing(t_arg *arg, t_ssl *ssl);

/*
**	Process
*/
void				ssl_main_process(char **av, t_ssl *ssl);

/*
** t_arg handling
*/
void				init_ssl_arg(t_arg *arg);
void				clear_ssl_arg(t_arg *arg);

/*
** Debug
*/
void				debug_arg(t_arg *arg);

#endif
