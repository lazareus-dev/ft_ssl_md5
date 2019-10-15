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

static void	print_md5(uint8_t *hash)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%02x", hash[i]);
		i++;
	}
}

void		ssl_md5(uint8_t *input, size_t size)
{
	t_md5_ctx	ctx;
	uint8_t		digest[16];

	ssl_md5_init(&ctx);
	ssl_md5_update(&ctx, input, size);
	ssl_md5_final(digest, &ctx);
	print_md5(digest);
}
