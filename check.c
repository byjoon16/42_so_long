/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:16:40 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 18:17:02 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *str, t_map *map)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	free(map);
	exit(1);
}

int	exit_esc(t_map *map)
{
	printf("ESC finish!");
	mlx_destroy_window(map->mlx, map->win);
	free(map);
	exit(0);
}

void	check_comp(t_map *map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i] != 'P' && map->to_map[i] != 'C' && \
			map->to_map[i] != 'E' && map->to_map[i] != '1' && \
			map->to_map[i] != '0')
		{
			ft_error("component", map);
		}
		i++;
	}
	return ;
}

void	check_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (i < map->x)
		{
			if (map->to_map[i] != '1')
				ft_error("wall", map);
		}
		else if (i % map->x == 0 || i % map->x == map->x - 1)
		{
			if (map->to_map[i] != '1')
				ft_error("wall", map);
		}
		else if (i > ft_strlen(map->to_map) - map->x)
		{
			if (map->to_map[i] != '1')
				ft_error("wall", map);
		}
		i++;
	}
	return ;
}

void	check_inside(t_map *map)
{
	int	i;
	int	count_p;
	int	count_e;

	i = 0;
	map->it_total = 0;
	count_p = 0;
	count_e = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i] == 'P')
			count_p++;
		else if (map->to_map[i] == 'C')
			map->it_total++;
		else if (map->to_map[i] == 'E')
			count_e++;
		i++;
	}
	if (count_p != 1)
		ft_error("count P", map);
	if (map->it_total == 0)
		ft_error("count C", map);
	if (count_e == 0)
		ft_error("count E", map);
	return ;
}
