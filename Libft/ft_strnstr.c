/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:53:24 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/17 18:06:54 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big2;

	i = 0;
	big2 = (char *)big;
	if (!little[i])
		return (big2);
	while (big2[i] && i < len)
	{
		j = 0;
		if (big2[i] == little[j])
		{
			while (big2[i + j] == little[j] && big2[i + j] && little[j])
			{
				if (i + j >= len)
					return (NULL);
				if (!little[j + 1])
					return (&big2[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
