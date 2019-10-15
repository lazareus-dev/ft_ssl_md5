/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256_final.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:39:42 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:39:50 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

void	final_padding(t_sha256_ctx *ctx)
{
	ctx->bitlen += ctx->datalen * 8;
	ctx->data[63] = ctx->bitlen;
	ctx->data[62] = ctx->bitlen >> 8;
	ctx->data[61] = ctx->bitlen >> 16;
	ctx->data[60] = ctx->bitlen >> 24;
	ctx->data[59] = ctx->bitlen >> 32;
	ctx->data[58] = ctx->bitlen >> 40;
	ctx->data[57] = ctx->bitlen >> 48;
	ctx->data[56] = ctx->bitlen >> 56;
}

void	reverse_bytes(uint8_t *(hash[]), t_sha256_ctx *ctx)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		(*hash)[i] = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 4] = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 8] = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
		(*hash)[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
		i += 1;
	}
}

void	ssl_sha256_final(uint8_t hash[], t_sha256_ctx *ctx)
{
	size_t i;

	i = ctx->datalen;
	if (ctx->datalen < 56)
	{
		ctx->data[i++] = 0x80;
		while (i < 56)
			ctx->data[i++] = 0x00;
	}
	else
	{
		ctx->data[i++] = 0x80;
		while (i < 64)
			ctx->data[i++] = 0x00;
		sha256_transform(ctx, ctx->data);
		memset(ctx->data, 0, 56);
	}
	final_padding(ctx);
	sha256_transform(ctx, ctx->data);
	reverse_bytes(&(hash), ctx);
}
