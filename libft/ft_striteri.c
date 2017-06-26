/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:27:03 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:52:07 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i < ft_strlen(s))
	{
		f((unsigned int)i, &s[i]);
		i++;
	}
}
