/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:10:21 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/04/06 11:34:03 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	const char	*src_cpy;

	if (dst == src)
		return (dst);
	dst_cpy = (char*)dst;
	src_cpy = (const char *)src;
	if (dst < src)
	{
		while (len-- > 0)
			*dst_cpy++ = *src_cpy++;
	}
	else
	{
		dst_cpy += len - 1;
		src_cpy += len - 1;
		while (len-- > 0)
			*dst_cpy-- = *src_cpy--;
	}
	return (dst);
}
