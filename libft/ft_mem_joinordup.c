/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrealloc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 18:22:28 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 18:29:54 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_mem_joinordup(void *mem1, void *mem2, size_t size1, size_t size2)
{
	uint8_t	*mem_out;
	size_t	size_out;

	if (!mem1 || size1 == 0)
		mem_out = (uint8_t *)ft_memdup(mem2, size2);
	else if (!mem2 || size2 == 0)
	{
		mem_out = (uint8_t *)ft_memdup(mem1, size1);
		ft_memdel(&mem1);
	}
	else
	{
		size_out = size1 + size2;
		mem_out = (uint8_t *)malloc(sizeof(char) * size_out);
		if (!mem_out)
			return (NULL);
		else
		{
			ft_memcpy(mem_out, mem1, size1);
			ft_memcpy(mem_out + size1, mem2, size2);
			ft_memdel(&mem1);
		}
	}
	return (mem_out);
}
