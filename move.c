/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:26:49 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 18:22:01 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press_key(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		exit_esc(map);
	else if (keycode == KEY_W)
		key_w(map);
	else if (keycode == KEY_A)
		key_a(map);
	else if (keycode == KEY_S)
		key_s(map);
	else if (keycode == KEY_D)
		key_d(map);
	return (0);
}

void	key_w(t_map	*map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i++] == 'P')
			break ;
	}
	i--;
	if (map->to_map[i - map->x] == '1')
		return ;
	if (map->to_map[i - map->x] == 'C')
		map->it_count++;
	if (map->to_map[i - map->x] == 'E' && map->it_total == map->it_count)
		exit_win(map);
	if (map->to_map[i - map->x] != 1 && map->to_map[i - map->x] != 'E')
	{
		map->to_map[i] = '0';
		map->to_map[i - map->x] = 'P';
		map->move_count++;
		printf("%d\n", map->move_count);
		fill_map(map);
	}
}

void	key_a(t_map	*map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i++] == 'P')
			break ;
	}
	i--;
	if (map->to_map[i - 1] == '1')
		return ;
	if (map->to_map[i - 1] == 'C')
		map->it_count++;
	if (map->to_map[i - 1] == 'E' && map->it_total == map->it_count)
		exit_win(map);
	if (map->to_map[i - 1] != 1 && map->to_map[i - 1] != 'E')
	{
		map->to_map[i] = '0';
		map->to_map[i - 1] = 'P';
		map->move_count++;
		printf("%d\n", map->move_count);
		fill_map(map);
	}
}

void	key_s(t_map	*map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i++] == 'P')
			break ;
	}
	i--;
	if (map->to_map[i + map->x] == '1')
		return ;
	if (map->to_map[i + map->x] == 'C')
		map->it_count++;
	if (map->to_map[i + map->x] == 'E' && map->it_total == map->it_count)
		exit_win(map);
	if (map->to_map[i + map->x] != 1 && map->to_map[i + map->x] != 'E')
	{
		map->to_map[i] = '0';
		map->to_map[i + map->x] = 'P';
		map->move_count++;
		printf("%d\n", map->move_count);
		fill_map(map);
	}
}

void	key_d(t_map	*map)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->to_map))
	{
		if (map->to_map[i++] == 'P')
			break ;
	}
	i--;
	if (map->to_map[i + 1] == '1')
		return ;
	if (map->to_map[i + 1] == 'C')
		map->it_count++;
	if (map->to_map[i + 1] == 'E' && map->it_total == map->it_count)
		exit_win(map);
	if (map->to_map[i + 1] != 1 && map->to_map[i + 1] != 'E')
	{
		map->to_map[i] = '0';
		map->to_map[i + 1] = 'P';
		map->move_count++;
		printf("%d\n", map->move_count);
		fill_map(map);
	}
}
