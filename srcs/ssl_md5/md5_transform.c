/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_transform.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:16:04 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 17:16:05 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

/*
**	MD5 specifies big endian byte order, but this implementation assumes
**	a little endian byte order CPU. Reverse all the bytes upon input, and
**	re-reverse them on output (in md5_final()).
*/

// static void	reverse(t_md5_transform *param, uint8_t *data)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (i < 16)
// 	{
// 		param->m[i] = (data[j]) + (data[j + 1] << 8) + (data[j + 2] << 16)
// 			+ (data[j + 3] << 24);
// 		i++;
// 		j += 4;
// 	}
// }

/* Decodes input (unsigned char) into output (uint32_t). Assumes len is
  a multiple of 4.
 */
static void decode(uint32_t *output, uint8_t *input, size_t len)
{
	size_t	i;
	size_t	j;

	for (i = 0, j = 0; j < len; i++, j += 4)
		output[i] = ((uint32_t)input[j]) | (((uint32_t)input[j+1]) << 8) |
			(((uint32_t)input[j+2]) << 16) | (((uint32_t)input[j+3]) << 24);
}

void		md5_transform(t_md5_ctx *ctx, uint8_t *data)
{
	t_md5_transform param;
	uint32_t		x[16];

	param.p[0] = ctx->state[0];
	param.p[1] = ctx->state[1];
	param.p[2] = ctx->state[2];
	param.p[3] = ctx->state[3];
	decode(x, data, 64);
	apply_ff(&param, x);
	apply_gg(&param, x);
	apply_hh(&param, x);
	apply_ii(&param, x);
	ctx->state[0] += param.p[0];
	ctx->state[1] += param.p[1];
	ctx->state[2] += param.p[2];
	ctx->state[3] += param.p[3];

	// ft_memset((uint8_t *)x, 0, sizeof(x));
}
