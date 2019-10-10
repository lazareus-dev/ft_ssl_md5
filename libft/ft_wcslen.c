/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcslen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/22 18:50:38 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:11:11 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const wchar_t *s)
{
	const wchar_t *p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
