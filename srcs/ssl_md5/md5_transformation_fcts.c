/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_transformation_fcts.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:01:28 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 17:01:30 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

/*
** ROTATE_LEFT rotates x left n bits.
*/

static uint32_t	rotate_left(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}

uint32_t		md5_ff(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->a += md5_f(param->b, param->c, param->d) + m + t;
	param->a = rotate_left(param->a, s);
	param->a += param->b;
	return (param->a);
}

uint32_t		md5_gg(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->a += md5_g(param->b, param->c, param->d) + m + t;
	param->a = rotate_left(param->a, s);
	param->a += param->b;
	return (param->a);
}

uint32_t		md5_hh(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->a += md5_h(param->b, param->c, param->d) + m + t;
	param->a = rotate_left(param->a, s);
	param->a += param->b;
	return (param->a);
}

uint32_t		md5_ii(t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->a += md5_i(param->b, param->c, param->d) + m + t;
	param->a = rotate_left(param->a, s);
	param->a += param->b;
	return (param->a);
}
