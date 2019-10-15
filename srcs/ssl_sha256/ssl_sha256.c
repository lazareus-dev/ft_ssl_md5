/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_sha256.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:41:58 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 15:41:59 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

static void	print_sha256(uint8_t *hash)
{
	size_t	i;

	i = 0;
	while (i < 32)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

void		ssl_sha256(uint8_t *input, size_t size)
{
	t_sha256_ctx	ctx;
	uint8_t			digest[32];

	ssl_sha256_init(&ctx);
	ssl_sha256_update(&ctx, input, size);
	ssl_sha256_final(digest, &ctx);
	print_sha256(digest);
}
