/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:13:13 by byjeon            #+#    #+#             */
/*   Updated: 2022/10/27 16:49:41 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("file open", map);
	line = get_next_line(fd);
	if (!line)
		ft_error("check map\n", map);
	map->y = 0;
	map->x = sl_strlen(line);
	map->to_map = sl_strdup(line);
	while (line)
	{
		free(line);
		map->y++;
		line = get_next_line(fd);
		if (line)
		{
			if (map->x != sl_strlen(line))
				ft_error_line("rectangle", map, line);
			map->to_map = sl_strjoin(map->to_map, line);
		}
	}
	close(fd);
}

t_img	*set_img(t_map	*map)
{
	t_img	*set;
	int		width;
	int		height;

	width = 64;
	height = 64;
	set = malloc(sizeof(t_img));
	if (!set)
		ft_error("malloc t_img", map);
	set->wall = mlx_xpm_file_to_image(map->mlx, "./img/w.xpm", \
									&width, &height);
	set->item = mlx_xpm_file_to_image(map->mlx, "./img/i.xpm", \
									&width, &height);
	set->play = mlx_xpm_file_to_image(map->mlx, "./img/c.xpm", \
									&width, &height);
	set->land = mlx_xpm_file_to_image(map->mlx, "./img/l.xpm", \
									&width, &height);
	set->fin = mlx_xpm_file_to_image(map->mlx, "./img/f.xpm", \
									&width, &height);
	return (set);
}

void	ft_help_fill(t_map *map, t_img *img, int w, int h)
{
	if (map->to_map[h * map->x + w] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, img->wall, w * 64, h * 64);
	}
	else if (map->to_map[h * map->x + w] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, img->item, w * 64, h * 64);
	}
	else if (map->to_map[h * map->x + w] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, img->play, w * 64, h * 64);
	}
	else if (map->to_map[h * map->x + w] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, img->fin, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->win, img->land, w * 64, h * 64);
	}
}

void	fill_map(t_map *map)
{
	t_img	*img;
	int		hei;
	int		wid;

	img = set_img(map);
	hei = 0;
	while (hei < map->y)
	{
		wid = 0;
		while (wid < map->x)
		{
			ft_help_fill(map, img, wid, hei);
			wid++;
		}
		hei++;
	}
	free(img);
}

int	exit_win(t_map *map)
{
	map->move_count++;
	printf("%d\n", map->move_count);
	printf("You have collected everything everywhere!\n");
	free(map);
	exit(0);
}
