/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:26:12 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 17:55:08 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;
	size_t j;
	size_t r;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	r = ft_strlen(s2);
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i == j && j == r)
		return (1);
	else
		return (0);
}
