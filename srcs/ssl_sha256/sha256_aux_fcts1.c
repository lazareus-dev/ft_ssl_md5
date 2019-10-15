/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256_aux_fcts1.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:40:46 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:40:48 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_sha256.h"

uint32_t		rotright(uint32_t a, uint32_t b)
{
	return ((a >> b) | (a << (32 - b)));
}

uint32_t		ch(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

uint32_t		maj(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}
