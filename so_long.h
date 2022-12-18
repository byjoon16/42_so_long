/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:20:33 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 18:24:06 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17


typedef struct s_map
{
	int		x;
	int		y;
	int		it_count;
	int		it_total;
	int		move_count;
	char	*to_map;
	void	*mlx;
	void	*win;
}	t_map;

typedef struct s_img
{
	void	*wall;
	void	*item;
	void	*play;
	void	*fin;
	void	*land;
}	t_img;

// check.c
int		ft_error(char *str, t_map *map);
int		exit_esc(t_map *map);
void	check_wall(t_map *map);
void	check_inside(t_map *map);
void	check_comp(t_map *map);

// line.c
char	*ft_help_name(char *s);
int		sl_strlen(char *str);
char	*sl_strdup(const char *s1);
char	*sl_strjoin(char *s1, char *s2);
int		sl_strncmp(char *s1, char *s2, int n);

// move.c
int		press_key(int keycode, t_map *map);
void	key_w(t_map	*map);
void	key_a(t_map	*map);
void	key_s(t_map	*map);
void	key_d(t_map	*map);

// map.c
int		exit_win(t_map *map);
void	read_map(t_map *map, char *file);
t_img	*set_img(t_map *map);
void	ft_help_fill(t_map *map, t_img *img, int w, int h);
void	fill_map(t_map *map);

// main.c
void	file_name(char *name);
int		ft_error_line(char *str, t_map *map, char *line);

#endif