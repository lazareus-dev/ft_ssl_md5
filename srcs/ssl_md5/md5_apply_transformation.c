/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5_transform_apply.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 17:43:50 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 17:43:51 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "../../includes/ssl_md5.h"

void	apply_ff(t_md5_transform *p, uint32_t x[16])
{
	md5_ff(0, p, x[0], S11, 0xd76aa478);
	md5_ff(3, p, x[1], S12, 0xe8c7b756);
	md5_ff(2, p, x[2], S13, 0x242070db);
	md5_ff(1, p, x[3], S14, 0xc1bdceee);
	md5_ff(0, p, x[4], S11, 0xf57c0faf);
	md5_ff(3, p, x[5], S12, 0x4787c62a);
	md5_ff(2, p, x[6], S13, 0xa8304613);
	md5_ff(1, p, x[7], S14, 0xfd469501);
	md5_ff(0, p, x[8], S11, 0x698098d8);
	md5_ff(3, p, x[9], S12, 0x8b44f7af);
	md5_ff(2, p, x[10], S13, 0xffff5bb1);
	md5_ff(1, p, x[11], S14, 0x895cd7be);
	md5_ff(0, p, x[12], S11, 0x6b901122);
	md5_ff(3, p, x[13], S12, 0xfd987193);
	md5_ff(2, p, x[14], S13, 0xa679438e);
	md5_ff(1, p, x[15], S14, 0x49b40821);
}

void	apply_gg(t_md5_transform *p, uint32_t x[16])
{
	md5_gg(0, p, x[1], S21, 0xf61e2562);
	md5_gg(3, p, x[6], S22, 0xc040b340);
	md5_gg(2, p, x[11], S23, 0x265e5a51);
	md5_gg(1, p, x[0], S24, 0xe9b6c7aa);
	md5_gg(0, p, x[5], S21, 0xd62f105d);
	md5_gg(3, p, x[10], S22, 0x02441453);
	md5_gg(2, p, x[15], S23, 0xd8a1e681);
	md5_gg(1, p, x[4], S24, 0xe7d3fbc8);
	md5_gg(0, p, x[9], S21, 0x21e1cde6);
	md5_gg(3, p, x[14], S22, 0xc33707d6);
	md5_gg(2, p, x[3], S23, 0xf4d50d87);
	md5_gg(1, p, x[8], S24, 0x455a14ed);
	md5_gg(0, p, x[13], S21, 0xa9e3e905);
	md5_gg(3, p, x[2], S22, 0xfcefa3f8);
	md5_gg(2, p, x[7], S23, 0x676f02d9);
	md5_gg(1, p, x[12], S24, 0x8d2a4c8a);
}

void	apply_hh(t_md5_transform *p, uint32_t x[16])
{
	md5_hh(0, p, x[5], S31, 0xfffa3942);
	md5_hh(3, p, x[8], S32, 0x8771f681);
	md5_hh(2, p, x[11], S33, 0x6d9d6122);
	md5_hh(1, p, x[14], S34, 0xfde5380c);
	md5_hh(0, p, x[1], S31, 0xa4beea44);
	md5_hh(3, p, x[4], S32, 0x4bdecfa9);
	md5_hh(2, p, x[7], S33, 0xf6bb4b60);
	md5_hh(1, p, x[10], S34, 0xbebfbc70);
	md5_hh(0, p, x[13], S31, 0x289b7ec6);
	md5_hh(3, p, x[0], S32, 0xeaa127fa);
	md5_hh(2, p, x[3], S33, 0xd4ef3085);
	md5_hh(1, p, x[6], S34, 0x04881d05);
	md5_hh(0, p, x[9], S31, 0xd9d4d039);
	md5_hh(3, p, x[12], S32, 0xe6db99e5);
	md5_hh(2, p, x[15], S33, 0x1fa27cf8);
	md5_hh(1, p, x[2], S34, 0xc4ac5665);
}

void	apply_ii(t_md5_transform *p, uint32_t x[16])
{
	md5_ii(0, p, x[0], S41, 0xf4292244);
	md5_ii(3, p, x[7], S42, 0x432aff97);
	md5_ii(2, p, x[14], S43, 0xab9423a7);
	md5_ii(1, p, x[5], S44, 0xfc93a039);
	md5_ii(0, p, x[12], S41, 0x655b59c3);
	md5_ii(3, p, x[3], S42, 0x8f0ccc92);
	md5_ii(2, p, x[10], S43, 0xffeff47d);
	md5_ii(1, p, x[1], S44, 0x85845dd1);
	md5_ii(0, p, x[8], S41, 0x6fa87e4f);
	md5_ii(3, p, x[15], S42, 0xfe2ce6e0);
	md5_ii(2, p, x[6], S43, 0xa3014314);
	md5_ii(1, p, x[13], S44, 0x4e0811a1);
	md5_ii(0, p, x[4], S41, 0xf7537e82);
	md5_ii(3, p, x[11], S42, 0xbd3af235);
	md5_ii(2, p, x[2], S43, 0x2ad7d2bb);
	md5_ii(1, p, x[9], S44, 0xeb86d391);
}
