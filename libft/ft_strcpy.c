/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:25:31 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:35:19 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) == i)
	{
		dst[i] = src[i];
		return (dst);
	}
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
	{
		dst[i] = '\0';
	}
	return (dst);
}
