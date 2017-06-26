/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:34:18 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:45:25 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_end(char const *s, size_t i, char c)
{
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		if (s[i + 1] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

static size_t	ft_count(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * ft_count(s, c) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(str[j] = ft_strsub(s, i, check_end(s, i, c) - i)))
				return (NULL);
			i = check_end(s, i, c);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	str[j] = NULL;
	return (str);
}
