/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:29 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:16:00 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	check;
	size_t	i;

	str = (char *)s;
	check = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == check)
		{
			return (&str[i]);
		}
		else
			i++;
	}
	return (NULL);
}
