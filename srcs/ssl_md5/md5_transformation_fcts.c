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

uint32_t		md5_ff(int turn, t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->p[turn % 4] += md5_f(param->p[(1 + turn) % 4],
		param->p[(2 + turn) % 4], param->p[(3 + turn) % 4]) + m + t;
	param->p[turn % 4] = rotate_left(param->p[turn % 4], s);
	param->p[turn % 4] += param->p[(1 + turn) % 4];
	return (param->p[turn % 4]);
}

uint32_t		md5_gg(int turn, t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->p[turn % 4] += md5_g(param->p[(1 + turn) % 4],
		param->p[(2 + turn) % 4], param->p[(3 + turn) % 4]) + m + t;
	param->p[turn % 4] = rotate_left(param->p[turn % 4], s);
	param->p[turn % 4] += param->p[(1 + turn) % 4];
	return (param->p[turn % 4]);
}

uint32_t		md5_hh(int turn, t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->p[turn % 4] += md5_h(param->p[(1 + turn) % 4],
		param->p[(2 + turn) % 4], param->p[(3 + turn) % 4]) + m + t;
	param->p[turn % 4] = rotate_left(param->p[turn % 4], s);
	param->p[turn % 4] += param->p[(1 + turn) % 4];
	return (param->p[turn % 4]);
}

uint32_t		md5_ii(int turn, t_md5_transform *param, uint32_t m,
	uint32_t s, uint32_t t)
{
	param->p[turn % 4] += md5_i(param->p[(1 + turn) % 4],
		param->p[(2 + turn) % 4], param->p[(3 + turn) % 4]) + m + t;
	param->p[turn % 4] = rotate_left(param->p[turn % 4], s);
	param->p[turn % 4] += param->p[(1 + turn) % 4];
	return (param->p[turn % 4]);
}
