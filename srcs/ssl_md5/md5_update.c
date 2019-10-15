/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_update.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 18:31:41 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 18:37:43 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

void		ssl_md5_update(t_md5_ctx *ctx, uint8_t *input, size_t input_len)
{
	size_t	i;
	size_t	index;
	size_t	part_len;

	index = (size_t)((ctx->bitlen[0] >> 3) & 0x3F);
	dprintf(1, "index = [%zu]\n", index);
	if ((ctx->bitlen[0] += ((uint32_t)input_len << 3)) < ((uint32_t)input_len << 3))
	{
		dprintf(1, "TRUUUUE");
		ctx->bitlen[1]++;
	}
	dprintf(1, "TRUC = [%u]\n", ((uint32_t)input_len >> 29));
	ctx->bitlen[1] += ((uint32_t)input_len >> 29);
	dprintf(1, "bitlen[1] = [%u]\n", ctx->bitlen[1]);

 	part_len = 64 - index;

	if (input_len >= part_len) {
		ft_memcpy((uint8_t *)&ctx->data[index], (uint8_t *)input, part_len);
		md5_transform(ctx, ctx->data);

		for (i = part_len; i + 63 < input_len; i += 64)
			md5_transform(ctx, &input[i]);

		index = 0;
	}
	else
		i = 0;

  /* Buffer remaining input */
	ft_memcpy((uint8_t *)&ctx->data[index], (uint8_t *)&input[i], input_len - i);

	// i = 0;
	// while (i < size)
	// {
	// 	ctx->data[ctx->datalen] = data[i];
	// 	ctx->datalen++;
	// 	if (ctx->datalen == 64)
	// 	{
	// 		md5_transform(ctx, ctx->data);
	// 		dbl_int_add(&(ctx->bitlen[0]), &(ctx->bitlen[1]), 512);
	// 		ctx->datalen = 0;
	// 	}
	// 	i++;
	// }
}
