/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:45:06 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/04/06 11:34:39 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

static int		ft_count_blank(char const *s, int b)
{
	int i;

	i = 0;
	while (is_blank(s[b]) == 1 && b >= 0)
	{
		i++;
		b--;
	}
	if (b == -1)
		return (i);
	b = 0;
	while (is_blank(s[b]) == 1)
	{
		b++;
		i++;
	}
	return (i);
}

static int		ft_string_start(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (is_blank(s[i]) == 0)
			break ;
		else
			i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	int				len;
	int				buf;
	int				i;

	i = 0;
	if (s == NULL)
		return (NULL);
	buf = ft_strlen(s);
	len = buf - ft_count_blank(s, buf - 1);
	start = ft_string_start(s);
	if ((str = ft_strsub(s, start, (size_t)len)) == 0)
		return (NULL);
	str[len] = '\0';
	return (str);
}
