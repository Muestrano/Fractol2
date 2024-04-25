/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:06:22 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/17 16:31:34 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size)
	{
		while (dst[i] && i < size)
			i++;
		j = 0;
		if (size != i)
		{
			while (src[j] && (j < size - i - 1))
			{
				dst[i + j] = src[j];
				j++;
			}
			dst[i + j] = 0;
		}
	}
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}
