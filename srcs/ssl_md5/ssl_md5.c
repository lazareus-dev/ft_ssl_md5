/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_md5.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:41:45 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 15:41:46 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

void	print_hash(uint8_t *hash)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ssl_md5_init(t_md5_ctx *ctx)
{
	ctx->datalen = 0;
	ctx->bitlen[0] = 0;
	ctx->bitlen[1] = 0;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xEFCDAB89;
	ctx->state[2] = 0x98BADCFE;
	ctx->state[3] = 0x10325476;
}

uint8_t	*ssl_md5(uint8_t *input, size_t size)
{
	t_md5_ctx	ctx;

	(void)size;
	ssl_md5_init(&ctx);
	ssl_md5_update(&ctx, input, size);
	
	print_hash(ssl_md5_final(&ctx));

	return (input);
}
