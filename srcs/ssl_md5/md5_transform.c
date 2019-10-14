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

static void	reverse(uint32_t *m[], uint32_t *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		m[i] = (data[j]) + (data[j + 1] << 8) + (data[j + 2] << 16)
			+ (data[j + 3] << 24);
		i++;
		j += 4;
	}
}

void		md5_transform(t_md5_ctx *ctx, uint8_t *data)
{
	t_md5_transform param;

	param.a = ctx->state[0];
	param.b = ctx->state[1];
	param.c = ctx->state[2];
	param.d = ctx->state[3];
	reverse(&(param.m), data);
	apply_ff(&param);
	apply_gg(&param);
	apply_hh(&param);
	apply_ii(&param);
	ctx->state[0] += param.a;
	ctx->state[1] += param.b;
	ctx->state[2] += param.c;
	ctx->state[3] += param.d;
}
