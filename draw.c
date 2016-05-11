/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:39:13 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/05/11 15:08:33 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_win *w, t_pts *pts1, t_pts *pts2, float len)
{
	float	x;
	float	y;
	int		nx;
	int		ny;
	float	i;

	i = 0;
	x = (float)pts2->x2d - (float)pts1->x2d;
	y = (float)pts2->y2d - (float)pts1->y2d;
	len = sqrt((x * x) + (y * y));
	while (i < len)
	{
		nx = (int)((float)pts1->x2d + (x * (i / len)));
		ny = (int)((float)pts1->y2d + (y * (i / len)));
		mlx_pixel_put(w->init, w->win, nx, ny, pts1->color);
		i++;
	}
}

void	draw_map(t_pts *pts, t_win *w)
{
	int		i;
	int		c;
	int		j;

	i = 0;
	c = 0;
	while (i < w->map_h)
	{
		j = 0;
		while (j < w->map->size)
		{
			if (j < (w->map->size - 1))
				draw(w, &pts[c], &pts[c + 1], 0);
			if (i < (w->map_h - 1))
				draw(w, &pts[c], &pts[c + w->map->size], 0);
			c++;
			j++;
		}
		i++;
	}
}
