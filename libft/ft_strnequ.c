/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:33:07 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:06:08 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t r;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	r = 0;
	while (s1[j] != '\0' && j < n)
		j++;
	while (s2[r] != '\0' && r < n)
		r++;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	if (i == j && j == r)
		return (1);
	else
		return (0);
}
