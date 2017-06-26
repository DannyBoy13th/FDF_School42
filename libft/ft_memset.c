/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:14:54 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:02:26 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			counter;

	temp = (unsigned char *)b;
	counter = 0;
	while (counter < len)
	{
		temp[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}
