/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:34:28 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 16:59:37 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;
	size_t r;

	i = 0;
	j = 0;
	r = 0;
	while (little[r] != '\0')
		r++;
	if (r == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
		{
			if (j == r - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
