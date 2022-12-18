/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:45:40 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 18:17:15 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_line(char *str, t_map *map, char *line)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	free(line);
	free(map);
	exit(1);
}

void	file_name(char *name)
{
	char	*temp;

	temp = ft_help_name(name);
	if (!temp)
	{
		write(2, "Error\n.ber", 10);
		exit(1);
	}
	if (sl_strncmp(temp, ".ber", 4) != 0)
	{
		write(2, "Error\n.ber", 10);
		exit(1);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		write(2, "Error\nac", 8);
		exit(1);
	}
	file_name(av[1]);
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("malloc t_map", map);
	map->move_count = 0;
	map->it_count = 0;
	read_map(map, av[1]);
	check_comp(map);
	check_wall(map);
	check_inside(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->x * 64, map->y * 64, "so_long");
	fill_map(map);
	mlx_hook(map->win, X_EVENT_KEY_PRESS, 0, &press_key, map);
	mlx_hook(map->win, X_EVENT_KEY_EXIT, 0, &exit_esc, map);
	mlx_loop(map->mlx);
	return (0);
}
