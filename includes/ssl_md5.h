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
** Constants for md5_transform routine
*/

# define S11 7
# define S12 12
# define S13 17
# define S14 22
# define S21 5
# define S22 9
# define S23 14
# define S24 20
# define S31 4
# define S32 11
# define S33 16
# define S34 23
# define S41 6
# define S42 10
# define S43 15
# define S44 21

typedef struct	s_md5_transform
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	m[16];
}				t_md5_transform;

/*
**	data: input data in 64bytes length
**	datalen: data length
**	bitlen:	data length in bits
**	states: A, B, C, D
*/

typedef struct	s_md5_ctx
{
	uint8_t		data[64];
	uint32_t	bitlen[2];
	uint32_t	state[4];
}				t_md5_ctx;

uint8_t			*ssl_md5(uint8_t *input, size_t size);

/*
**	Process
*/

void			ssl_md5_init(t_md5_ctx *ctx);
void			ssl_md5_update(t_md5_ctx *ctx, uint8_t data[], size_t size);
void			md5_transform(t_md5_ctx *ctx, uint8_t *data);
void			ssl_md5_final(uint8_t digest[16], t_md5_ctx *ctx);

/*
**	Auxiliary functions
*/

uint32_t		md5_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t		md5_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t		md5_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t		md5_i(uint32_t x, uint32_t y, uint32_t z);

uint32_t		dbl_int_add(uint32_t *a, uint32_t *b, uint32_t c);

/*
**	Transformation functions
** 	for rounds 1, 2, 3, and 4
*/

uint32_t		md5_ff(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t);
uint32_t		md5_gg(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t);
uint32_t		md5_hh(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t);
uint32_t		md5_ii(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t);

/*
** Apply transformation functions
*/

void			apply_ff(t_md5_transform *p, uint32_t x[16]);
void			apply_gg(t_md5_transform *p, uint32_t x[16]);
void			apply_hh(t_md5_transform *p, uint32_t x[16]);
void			apply_ii(t_md5_transform *p, uint32_t x[16]);

/*
** Debug
*/

void				debug_params(t_md5_transform *param);
void				debug_md5_ctx(t_md5_ctx *ctx);

#endif
