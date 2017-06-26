/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:35:43 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:42:50 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	i = ft_check_start(s);
	j = ft_check_end(s);
	str = ft_strsub(s, i, j - i);
	if (str == NULL)
		return (NULL);
	return (str);
}
