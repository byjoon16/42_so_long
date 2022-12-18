/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:40:34 by byjeon            #+#    #+#             */
/*   Updated: 2022/12/14 18:19:50 by byjeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_help_name(char *s)
{
	int	i;

	if (ft_strlen(s) <= 4)
		return (NULL);
	i = ft_strlen(s) - 4;
	return ((char *)s + i);
}

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*sl_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (s1[len] != '\0' && s1[len] != '\n')
		len++;
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*sl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (sl_strlen(s1) + sl_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0' && s1[i] != '\n')
			str[i] = s1[i];
	while (s2[j] != '\0' && s2[j] != '\n')
		str[i++] = s2[j++];
	str[sl_strlen(s1) + sl_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	sl_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
