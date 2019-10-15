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
	ctx->bitlen[0] += ((uint32_t)input_len << 3);
	part_len = 64 - index;
	if (input_len >= part_len)
	{
		ft_memcpy((uint8_t *)&ctx->data[index], (uint8_t *)input, part_len);
		md5_transform(ctx, ctx->data);
		i = part_len;
		while (i + 63 < input_len)
		{
			md5_transform(ctx, &input[i]);
			i += 64;
		}
		index = 0;
	}
	else
		i = 0;
	ft_memcpy((uint8_t *)&ctx->data[index], (uint8_t *)&input[i],
		input_len - i);
}
