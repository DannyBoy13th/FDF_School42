/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:27:34 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:58:19 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long i;
	long res;
	long j;

	i = 0;
	j = 1;
	res = 0;
	while (str[i] == '0' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (!(str[i] > 47 && str[i] < 58) && str[i] != 45 && str[i] != 43)
		return (0);
	if (str[i] == 45)
		j = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * j);
}
