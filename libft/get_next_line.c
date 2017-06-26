/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:54:18 by dsoloshe          #+#    #+#             */
/*   Updated: 2017/03/28 17:40:24 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcomb(char *s1, char *s2)
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

static int		read_ln(int fd, char **buf)
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
		res = ft_strcomb(*buf, temp);
	}
	*buf = ft_strdup(res);
	free(res);
	return (num_bytes);
}

int				count_n(char *input)
{
	int i;

	i = 0;
	while (input[i] != '\n' && input[i] != '\0')
	{
		i++;
	}
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static t_lines res;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > MAX_FD)
		return (-1);
	if (res.cont[fd] == NULL)
		res.cont[fd] = ft_strnew(BUFF_SIZE);
	if (read_ln(fd, &res.cont[fd]) < 0)
		return (-1);
	while (read_ln(fd, &res.cont[fd]) > 0)
		read_ln(fd, &res.cont[fd]);
	if (ft_strchr(res.cont[fd], '\n') != NULL)
	{
		res.endl_loc = ft_strchr(res.cont[fd], '\n');
		*line = ft_strsub(res.cont[fd], 0, count_n(res.cont[fd]));
		res.cont[fd] = ft_strcpy(res.cont[fd], ft_strdup(res.endl_loc + 1));
		return (1);
	}
	if (ft_strlen(res.cont[fd]) > 0)
	{
		*line = ft_strsub(res.cont[fd], 0, ft_strlen(res.cont[fd]));
		res.cont[fd] = NULL;
		return (1);
	}
	return (0);
}
