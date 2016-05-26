/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:43:40 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/05/26 17:09:51 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose(void *w)
{
	print_selection(w);
	calc(w, 0);
	return (1);
}

void	move_img(t_win *w, int keycode)
{
	if (keycode == 24)
	{
		((t_win*)w)->zoomx += ((t_win*)w)->zoomx / 2;
		((t_win*)w)->zoomy = ((t_win*)w)->zoomx / 2;
		((t_win*)w)->pad += ((t_win*)w)->pad / 2;
	}
	if (keycode == 27 && ((t_win*)w)->zoomx > 2)
	{
		((t_win*)w)->zoomx -= ((t_win*)w)->zoomx / 2;
		((t_win*)w)->zoomy = ((t_win*)w)->zoomx / 2;
		((t_win*)w)->pad -= ((t_win*)w)->pad / 2;
	}
	if (keycode == 36)
	{
		((t_win*)w)->yoffset = 0;
		((t_win*)w)->xoffset = 0;
		((t_win*)w)->pad = 2;
		((t_win*)w)->zoomx = 32;
		((t_win*)w)->zoomy = ((t_win*)w)->zoomx / 2;
	}
	mlx_destroy_image(w->init, w->img);
	w->img = mlx_new_image(w->init, WIDTH, HEIGHT);
	mlx_put_image_to_window(w->init, w->win, w->img, 0, 0);
}

int		key_hook(int keycode, void *w)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_win*)w)->init, ((t_win*)w)->win);
		exit(0);
	}
	if (keycode == 126)
		((t_win*)w)->yoffset -= 10;
	if (keycode == 125)
		((t_win*)w)->yoffset += 10;
	if (keycode == 123)
		((t_win*)w)->xoffset -= 10;
	if (keycode == 124)
		((t_win*)w)->xoffset += 10;
	if (keycode == 32)
		((t_win*)w)->pad += 1;
	if (keycode == 2)
		((t_win*)w)->pad -= 1;
	move_img(w, keycode);
	expose(w);
	return (keycode);
}

void	ft_init(t_win *w)
{
	w->map = ft_parsing(w);
	w->init = mlx_init();
	w->win = mlx_new_window(w->init, WIDTH, HEIGHT, "Fdf");
	w->img = mlx_new_image(w->init, WIDTH, HEIGHT);
	w->addr = mlx_get_data_addr(w->img, &w->bpp, &w->size_line, &w->end);
	w->xoffset = 0;
	w->yoffset = 0;
	w->pad = 2;
	w->zoomx = 32;
	w->zoomy = w->zoomx / 2;
	mlx_expose_hook(w->win, expose, w);
	mlx_key_hook(w->win, key_hook, w);
	mlx_loop(w->init);
}

int		main(int ac, char **av)
{
	static t_win	w;

	w.size = 0;
	if (ac == 2)
	{
		w.path = av[1];
		ft_init(&w);
	}
	if (ac < 2)
		ft_putstr("Insert Map\n");
	return (0);
}
