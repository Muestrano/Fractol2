/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:17:34 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/18 19:33:03 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_fill(char *toa, long int n, int len)
{
	int	i;

	i = 0;
	if (!n)
	{
		toa[0] = 48;
		toa[1] = 0;
		return (toa);
	}
	if (n < 0)
	{
		toa[i] = '-';
		n *= -1;
	}
	toa[len] = 0;
	while (n)
	{
		toa[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (toa);
}

char	*ft_itoa(int n)
{
	char	*toa;
	int		len;
	int		n2;

	len = 0;
	if (n < 0)
		len++;
	n2 = n;
	while (n2)
	{
		n2 = n2 / 10;
		len++;
	}
	if (!n)
		toa = (char *)malloc(sizeof(char) * 2);
	else
		toa = (char *)malloc(sizeof(char) * (len + 1));
	if (!toa)
		return (NULL);
	toa = ft_fill(toa, n, len);
	if (n)
		toa[len] = 0;
	return (toa);
}
