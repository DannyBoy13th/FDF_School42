/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:12:19 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:42:27 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	long long	j;
	int			i;
	char		*str;

	j = n;
	i = ft_num_count(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		j = j * -1;
		str[0] = '-';
	}
	while (j >= 10)
	{
		str[i - 1] = (j % 10) + '0';
		j = j / 10;
		i--;
	}
	str[i - 1] = j + '0';
	return (str);
}
