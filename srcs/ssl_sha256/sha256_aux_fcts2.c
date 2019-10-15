/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256_aux_fcts2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:40:52 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:40:53 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

uint32_t	ep0(uint32_t x)
{
	return (rotright(x, 2) ^ rotright(x, 13) ^ rotright(x, 22));
}

uint32_t	ep1(uint32_t x)
{
	return (rotright(x, 6) ^ rotright(x, 11) ^ rotright(x, 25));
}

uint32_t	sig0(uint32_t x)
{
	return (rotright(x, 7) ^ rotright(x, 18) ^ (x >> 3));
}

uint32_t	sig1(uint32_t x)
{
	return (rotright(x, 17) ^ rotright(x, 19) ^ (x >> 10));
}
