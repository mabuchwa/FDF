/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:23:06 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/05/11 15:47:56 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(t_pts pts, t_win *w)
{
	int		color;
	int		r;
	int		g;
	int		b;

	g = ((pts.z3d * 50) + (w->pad * 2)) % 255;
	r = ((pts.z3d * 50) + (w->pad * 9)) % 255;
	b = (10 + (w->pad * 15)) % 255;
	color = (r & 0x00FF) << 16 | (g & 0x00FF) << 8 | (b & 0x00FF);
	if (pts.z3d == 0)
		color = 0x00FFFFFF;
	return (color);
}

void	calcul_2d(t_pts *pts, t_win *w, int total)
{
	int		i;
	int		j;

	i = 0;
	while (i < total)
	{
		j = 0;
		while (j < w->map[j].size)
		{
			pts[i].y2d = ((pts[i].x3d + pts[i].y3d) * w->zoomy);
			pts[i].x2d = ((pts[i].x3d - pts[i].y3d) * w->zoomx);
			j++;
			i++;
		}
	}
	center_map(w, pts, total);
	draw_map(pts, w);
}

void	init(t_pts *pts, int i)
{
	pts[i].x2d = 0;
	pts[i].y2d = 0;
	pts[i].color = 0;
}

void	calc(t_win *w, int i)
{
	int		j;
	int		y;
	int		total;
	t_pts	*pts;

	y = 0;
	total = w->map_h * w->map[i].size;
	pts = (t_pts*)malloc(sizeof(t_pts) * (total + 1));
	pts[w->map_h].color = -1;
	while (i < total)
	{
		j = 0;
		while (j < w->map[y].size)
		{
			pts[i].y3d = y;
			pts[i].x3d = j;
			init(pts, i);
			pts[i].z3d = w->map[y].line[j];
			j++;
			i++;
		}
		y++;
	}
	calcul_2d(pts, w, total);
}
