/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:32:30 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/18 15:56:54 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest2 < src2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	n++;
	if (dest2 >= src2)
	{
		while (--n)
			dest2[n - 1] = src2[n - 1];
	}
	return (dest2);
}
