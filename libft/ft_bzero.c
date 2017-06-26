/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:10:32 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:28:12 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;
	size_t	counter;

	temp = (char *)s;
	counter = 0;
	while (counter < n)
	{
		temp[counter] = 0;
		counter++;
	}
}
