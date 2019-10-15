/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_sha256.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 13:10:58 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 19:11:35 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SSL_SHA256_H
# define SSL_SHA256_H

typedef struct	s_sha256_param
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	t1;
	uint32_t	t2;
	uint32_t	m[64];
}				t_sha256_param;

typedef struct	s_sha256_ctx
{
	uint8_t		data[64];
	uint32_t	datalen;
	uint64_t	bitlen;
	uint32_t	state[8];
}				t_sha256_ctx;

void			ssl_sha256(uint8_t *input, size_t size);
void			ssl_sha256_init(t_sha256_ctx *ctx);
void			ssl_sha256_update(t_sha256_ctx *ctx, const uint8_t data[], size_t len);
void			sha256_transform(t_sha256_ctx *ctx, uint8_t data[]);
void			ssl_sha256_final(uint8_t hash[], t_sha256_ctx *ctx);

/*
**	Transform and auxiliary functions
*/

uint32_t		rotright(uint32_t a,uint32_t b);
uint32_t		ch(uint32_t x,uint32_t y,uint32_t z);
uint32_t		maj(uint32_t x,uint32_t y,uint32_t z);
uint32_t		ep0(uint32_t x);
uint32_t		ep1(uint32_t x);
uint32_t		sig0(uint32_t x);
uint32_t		sig1(uint32_t x);

#endif
