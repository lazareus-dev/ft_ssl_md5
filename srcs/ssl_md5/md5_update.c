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

void	ssl_md5_update(t_md5_ctx *ctx, uint8_t data[], size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ctx->data[ctx->datalen] = data[i];
		ctx->datalen++;
		if (ctx->datalen == 64)
		{
			md5_transform(ctx, ctx->data);
			dbl_int_add(&(ctx->bitlen[0]), &(ctx->bitlen[1]), 512);
			ctx->datalen = 0;
		}
		i++;
	}
}
