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

/*
** Encodes input (uint32_t) into output (unsigned char). Assumes len is
** a multiple of 4.
*/

static void	encode(uint8_t *output, uint32_t *input, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (j < len)
	{
		output[j] = (unsigned char)(input[i] & 0xff);
		output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
		output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
		output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
		i += 1;
		j += 4;
	}
}

void		ssl_md5_final(uint8_t digest[16], t_md5_ctx *ctx)
{
	uint8_t			bits[8];
	size_t			index;
	size_t			pad_len;
	static uint8_t	padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	encode(bits, ctx->bitlen, 8);
	index = (unsigned int)((ctx->bitlen[0] >> 3) & 0x3f);
	pad_len = (index < 56) ? (56 - index) : (120 - index);
	ssl_md5_update(ctx, padding, pad_len);
	ssl_md5_update(ctx, bits, 8);
	encode(digest, ctx->state, 16);
}
