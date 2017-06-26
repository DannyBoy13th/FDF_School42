/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:14:37 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 17:51:33 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sour;
	size_t				i;

	dest = dst;
	sour = src;
	i = 0;
	if (dest > sour)
	{
		i = len;
		while (i != 0)
		{
			dest[i - 1] = sour[i - 1];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = sour[i];
			i++;
		}
	}
	return (dst);
}
