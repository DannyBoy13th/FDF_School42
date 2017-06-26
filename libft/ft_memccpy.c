/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:14:08 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 17:13:05 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;

	i = 0;
	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = sour[i];
		if (dest[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
