/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_md5.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 13:07:41 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 13:07:52 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SSL_MD5_H
# define SSL_MD5_H

/*
**	buffer: input data in 64bytes length
**	datalen: data length
**	bitlen:	data length in bits
**	states: A, B, C, D
*/
typedef struct	s_md5_ctx
{
	uint8_t		buffer[64];
	uint32_t	datalen;
	uint32_t	bitlen[2];
	uint32_t	state[4];
}				t_md5_ctx;

uint8_t			*ssl_md5(uint8_t *input);
void			ssl_md5_init(t_md5_ctx *ctx);
void			ssl_md5_update(t_md5_ctx *ctx);
void			ssl_md5_final(t_md5_ctx *ctx);

#endif
