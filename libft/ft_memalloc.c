/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:12:32 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:14:34 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = malloc(size);
	if (mem == NULL || ft_strlen(mem) > size)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
