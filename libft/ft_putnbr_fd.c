/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:23:58 by dsoloshe          #+#    #+#             */
/*   Updated: 2016/12/22 19:54:12 by dsoloshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long j;

	j = n;
	if (j < 0)
	{
		j = j * -1;
		ft_putchar_fd(45, fd);
	}
	if (j >= 10)
	{
		ft_putnbr_fd(j / 10, fd);
		ft_putnbr_fd(j % 10, fd);
	}
	else
		ft_putchar_fd(j + '0', fd);
}
