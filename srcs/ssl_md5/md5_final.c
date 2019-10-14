/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_final.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 18:44:23 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 18:44:25 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

static uint8_t	*reverse(t_md5_ctx *ctx)
{
	uint8_t *hash;
	size_t	i;

	hash = (uint8_t *)malloc(sizeof(uint8_t) * 64);
	i = 0;
	while (i < 4)
	{ 
		hash[i]    = (ctx->state[0] >> (i*8)) & 0x000000ff;
		hash[i+4]  = (ctx->state[1] >> (i*8)) & 0x000000ff;
		hash[i+8]  = (ctx->state[2] >> (i*8)) & 0x000000ff;
		hash[i+12] = (ctx->state[3] >> (i*8)) & 0x000000ff;
		++i;
	}
	return (hash);
}

static void	padding_last_block(t_md5_ctx *ctx)
{
	ctx->data[56] = ctx->bitlen[0];
	ctx->data[57] = ctx->bitlen[0] >> 8;
	ctx->data[58] = ctx->bitlen[0] >> 16;
	ctx->data[59] = ctx->bitlen[0] >> 24;
	ctx->data[60] = ctx->bitlen[1];
	ctx->data[61] = ctx->bitlen[1] >> 8;
	ctx->data[62] = ctx->bitlen[1] >> 16;
	ctx->data[63] = ctx->bitlen[1] >> 24;
}

uint8_t		*ssl_md5_final(t_md5_ctx *ctx)
{
	size_t	i;
	uint8_t	*hash;

	i = 0;
	if (ctx->datalen < 56)
	{
		ctx->data[i++] = 0x80;
		while (i < 56)
        	ctx->data[i++] = 0x00;
	}
	else if (ctx->datalen >= 56)
	{
		ctx->data[i++] = 0x80;
		while (i < 64)
			ctx->data[i++] = 0x00;
		md5_transform(ctx, ctx->data);
		ft_memset(ctx->data, 0, 56);
	}
	dbl_int_add(ctx->bitlen[0], ctx->bitlen[1], 8 * ctx->datalen);
	padding_last_block(ctx);
	md5_transform(ctx, ctx->data);
	hash = reverse(ctx);
	return (hash);
}
