/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:31:36 by mabuchwa          #+#    #+#             */
/*   Updated: 2016/05/19 11:20:23 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i]) == 0) && str[i] != ' ')
		{
			perror("Fdf");
			exit(1);
		}
		i++;
	}
}

void	check_file(char *file)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Fdf");
		exit(1);
	}
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		if (ret == -1)
		{
			perror("Fdf");
			exit(1);
		}
	}
	close(fd);
	free(buff);
}

t_map	*get_coor(t_win *w, t_lst *lst)
{
	int		i;
	t_map	*map;
	t_lst	*tmp;

	i = 0;
	tmp = lst;
	map = (t_map*)malloc(sizeof(t_map) * (w->map_h + 1));
	map[w->map_h].size = 0;
	while (tmp != NULL && i < w->map_h)
	{
		map[i].size = tab_len(lst);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (lst != NULL && i < w->map_h)
	{
		get_height(lst, &map[i]);
		lst = lst->next;
		i++;
	}
	return (map);
}

t_map	*ft_parsing(t_win *w)
{
	t_lst	*lst;
	t_lst	*new;
	t_map	*map;
	char	*line;
	int		i;

	w->map_h = 0;
	lst = NULL;
	check_file(w->path);
	if (!(w->fd = open(w->path, O_RDONLY)))
		exit(0);
	while ((i = get_next_line(w->fd, &line)) > 0)
	{
		new = (t_lst*)malloc(sizeof(t_lst));
		new->data = line;
		new->next = NULL;
		lst_pushback(&lst, new);
		check_map(new->data);
		w->map_h++;
	}
	close(w->fd);
	map = get_coor(w, lst);
	return (map);
}
