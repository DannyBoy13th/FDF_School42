/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:34:02 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 20:10:41 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
	{
		i--;
	}
	if (s[i] == '\0' && c == '\0')
	{
		return ((char *)&s[i]);
	}
	if (i == 0 && s[i] != c)
	{
		return (NULL);
	}
	return ((char *)&s[i]);
}
