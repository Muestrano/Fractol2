/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:16:25 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/24 17:31:40 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sign(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	return (nb);
}

int	ft_unit(int nb, int fd)
{
	char	a;

	if (nb < 10)
	{
		a = '0' + nb;
		write (fd, &a, 1);
		return (0);
	}
	else
	{
		ft_unit(nb / 10, fd);
		a = '0' + nb % 10;
		write(fd, &a, 1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		n = ft_sign(n, fd);
		ft_unit(n, fd);
	}
}
