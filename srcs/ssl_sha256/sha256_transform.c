/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256_transform.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:36:01 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:36:03 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

void	finish_transform(t_sha256_param *param, t_sha256_ctx *ctx)
{
	ctx->state[0] += param->a;
	ctx->state[1] += param->b;
	ctx->state[2] += param->c;
	ctx->state[3] += param->d;
	ctx->state[4] += param->e;
	ctx->state[5] += param->f;
	ctx->state[6] += param->g;
	ctx->state[7] += param->h;
}

void	compute_param(t_sha256_param *param, uint32_t k[64])
{
	size_t			i;

	i = 0;
	while (i < 64)
	{
		param->t1 = param->h + ep1(param->e) +
			ch(param->e, param->f, param->g) +
			k[i] + param->m[i];
		param->t2 = ep0(param->a) + maj(param->a, param->b, param->c);
		param->h = param->g;
		param->g = param->f;
		param->f = param->e;
		param->e = param->d + param->t1;
		param->d = param->c;
		param->c = param->b;
		param->b = param->a;
		param->a = param->t1 + param->t2;
		i += 1;
	}
}

void	init_param(t_sha256_param *param, t_sha256_ctx *ctx)
{
	param->a = ctx->state[0];
	param->b = ctx->state[1];
	param->c = ctx->state[2];
	param->d = ctx->state[3];
	param->e = ctx->state[4];
	param->f = ctx->state[5];
	param->g = ctx->state[6];
	param->h = ctx->state[7];
}

void	start_transform(t_sha256_param *param, uint8_t data[])
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		param->m[i] = (data[j] << 24) | (data[j + 1] << 16) |
			(data[j + 2] << 8) | (data[j + 3]);
		i += 1;
		j += 4;
	}
	while (i < 64)
	{
		param->m[i] = sig1(param->m[i - 2]) + param->m[i - 7]
			+ sig0(param->m[i - 15]) + param->m[i - 16];
		i++;
	}
}

void	sha256_transform(t_sha256_ctx *ctx, uint8_t data[])
{
	t_sha256_param	param;
	static uint32_t	k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

	start_transform(&param, data);
	init_param(&param, ctx);
	compute_param(&param, k);
	finish_transform(&param, ctx);
}
