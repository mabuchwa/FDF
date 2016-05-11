/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:29:47 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/04/06 11:18:52 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i)
				&& i < (n - 1)))
		i++;
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
	return (0);
}
