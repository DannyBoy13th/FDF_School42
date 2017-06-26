/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:23:07 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/06/13 16:10:17 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_line(int fd, char **buf)
{
	char		*temp;
	int			num_bytes;
	char		*res;

	temp = ft_strnew(ft_strlen(*buf) + BUFF_SIZE);
	res = ft_strnew(1);
	num_bytes = read(fd, temp, BUFF_SIZE);
	if (num_bytes == 0)
	{
		free(res);
		free(temp);
		return (0);
	}
	if (num_bytes < 0)
		return (-1);
	if (num_bytes > 0)
	{
		free(res);
		temp[num_bytes] = '\0';
		res = ft_strcombine(*buf, temp);
	}
	*buf = ft_strdup(res);
	free(res);
	return (num_bytes);
}

void	count_ints(char *str, t_fdf *res)
{
	res->count_x = 1;
	res->dr.a = 0;
	res->dr.c = 0;
	res->dr.b = 0;
	while (res->dr.a < res->count_y)
	{
		res->count_x = 1;
		while (str[res->dr.b] != '\n' && str[res->dr.b + 1] != '\0')
		{
			if (ft_isalnum(str[res->dr.b]) &&
				(str[res->dr.b + 1] == ' ' || str[res->dr.b + 1] == '\0'))
				res->count_x++;
			res->dr.b++;
		}
		if (res->dr.c == 0)
			res->dr.c = res->count_x;
		if (res->count_x == 1 || res->count_x != res->dr.c)
		{
			ft_putstr("Wrong Map!");
			exit(0);
		}
		res->dr.a++;
		res->dr.b++;
	}
}

void	count_rows(char *str, t_fdf *res)
{
	int i;

	res->count_y = 0;
	i = 0;
	if (str[i] == '\0')
	{
		ft_putstr("Empty Map!");
		exit(0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_putstr("Wrong Map!");
			exit(0);
		}
		if (str[i] == '\n')
			res->count_y++;
		i++;
	}
}

char	*ft_strcombine(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

void	parse_ints(t_fdf *res)
{
	int i;
	int j;

	j = 0;
	res->line = ft_strsplit(res->file, ' ');
	while (j < res->count_y)
	{
		i = 0;
		while (i < res->count_x)
		{
			check_for_color(res, j * (res->count_x - 1) + i);
			if (res->com == 1)
				res->cord[j][i].h = ft_atoi(res->line[j * (res->count_x) + i]);
			else
				res->cord[j][i].h =
					ft_atoi(res->line[j * (res->count_x - 1) + i]);
			i++;
		}
		j++;
	}
}
