/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:11:31 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/04/06 11:56:19 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (*alst == NULL || alst == NULL)
		return ;
	while (tmp != NULL)
	{
		del((tmp)->content, (tmp)->content_size);
		*alst = tmp;
		free(*alst);
		*alst = NULL;
		tmp = (tmp)->next;
	}
}
