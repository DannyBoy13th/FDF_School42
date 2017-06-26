/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:25:52 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 17:59:45 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (dest != NULL)
	{
		ft_strcpy(dest, s1);
		return (dest);
	}
	else
		return (dest);
}
