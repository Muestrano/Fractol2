/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:10:49 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/24 16:44:55 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	c = (char)c;
	s2 = (char *)s;
	while (i < n)
	{
		if (s2[i] == c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
