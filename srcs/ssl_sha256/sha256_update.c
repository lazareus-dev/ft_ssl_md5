/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256_update.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:39:32 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:39:34 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

void		ssl_sha256_update(t_sha256_ctx *ctx, const uint8_t data[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ctx->data[ctx->datalen] = data[i];
		ctx->datalen++;
		if (ctx->datalen == 64)
		{
			sha256_transform(ctx, ctx->data);
			ctx->bitlen += 512;
			ctx->datalen = 0;
		}
		i++;
	}
}
