/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_aux.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 14:45:42 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 14:45:43 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

uint32_t	md5_f(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | (~x & z));
}

uint32_t	md5_g(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & z) | (y & ~z));
}

uint32_t	md5_h(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x ^ y ^ z));
}

uint32_t	md5_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}

/*
** dbl_int_add treats two unsigned ints a and b as one 64-bit integer and
** adds c to it
*/

uint64_t	dbl_int_add(uint32_t a, uint32_t b, uint32_t c)
{
	if (a > 0xffffffff - c)
		++b;
	a += c;
	return (a);
}