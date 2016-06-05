/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 10:55:34 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/06/05 16:18:23 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define WIDTH		1600
# define HEIGHT		900

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*data;
}					t_lst;

typedef struct		s_map
{
	int				size;
	int				*line;
}					t_map;

typedef struct		s_win
{
	void			*init;
	void			*win;
	void			*img;
	int				size_line;
	int				end;
	char			*addr;
	char			*path;
	int				bpp;
	t_map			*map;
	int				xoffset;
	int				yoffset;
	int				zoomy;
	int				zoomx;
	int				pad;
	int				lenx;
	int				leny;
	int				map_h;
	int				size;
	int				psize;
	int				map_w;
	int				fd;
	int				len;
}					t_win;

typedef struct		s_point
{
	int				x3d;
	int				y3d;
	int				z3d;
	int				x2d;
	int				y2d;
	int				color;
}					t_pts;

t_map				*ft_parsing(t_win *w);
void				ft_init(t_win *w);
void				calc(t_win *win, int i);
void				draw(t_win *w, t_pts *pts1, t_pts *pts2, float len);
void				draw_map(t_pts *pts, t_win *w);
int					tab_len(t_lst *lst);
void				lst_pushback(t_lst **list, t_lst *new);
void				get_height(t_lst *lst, t_map *map);
void				print_selection(t_win *w);
void				freedom(char **tab);
void				center_map(t_win *w, t_pts *pts, int total);
int					color(t_pts pts, t_win *w);

#endif
