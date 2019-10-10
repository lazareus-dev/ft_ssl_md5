/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 18:22:28 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 15:19:11 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	char	*p;
	char	*s;
	size_t	i;

	i = 0;
	p = ft_memalloc(n);
	s = (char *)src;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
