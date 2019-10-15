/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_raw_input.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tle-coza <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:34:39 by tle-coza     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:34:53 by tle-coza    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_raw_input(int fd, t_mem *memory)
{
	uint8_t	*input;
	char	buffer[4097];
	int		retread;
	size_t	len;

	input = NULL;
	retread = 0;
	len = 0;
	ft_bzero(buffer, 4097);
	while ((retread = read(fd, buffer, 4096)))
	{
		input = ft_mem_joinordup(input, buffer, len, retread);
		len += retread;
	}
	memory->content = input;
	memory->len = len;
}
