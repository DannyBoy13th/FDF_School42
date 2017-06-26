/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:12:59 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:10:39 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tsrc;
	char	*tdst;
	size_t	i;

	i = 0;
	tsrc = (char *)src;
	tdst = (char *)dst;
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (dst);
}
