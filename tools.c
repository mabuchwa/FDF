/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:17:51 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/06/05 16:37:10 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_win *w, t_pts *pts, int total)
{
	int		i;
	int		j;
	int		xcenter;
	int		ycenter;

	i = 0;
	w->lenx = pts[total - 1].x2d - pts[i].x2d;
	w->leny = pts[total - 1].y2d - pts[i].y2d;
	xcenter = (WIDTH / 2) - (w->lenx / 2);
	ycenter = (HEIGHT / 2) - (w->leny / 2);
	while (i < total)
	{
		j = 0;
		while (j < w->map[j].size)
		{
			pts[i].y2d += (w->yoffset + ycenter) - (pts[i].z3d * w->pad);
			pts[i].x2d += w->xoffset + xcenter;
			pts[i].color = color(pts[i], w);
			i++;
			j++;
		}
	}
}

void	get_height(t_lst *lst, t_map *map)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(lst->data, ' ');
	map->line = (int*)malloc(sizeof(int) * (map->size));
	while (tab[i])
	{
		map->line[i] = ft_atoi(tab[i]);
		i++;
	}
}

int		tab_len(t_lst *lst)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(lst->data, ' ');
	while (tab[i])
		i++;
	freedom(tab);
	return (i);
}

void	lst_pushback(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	freedom(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
