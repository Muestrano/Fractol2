/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:03:07 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/17 18:30:59 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len2;
	char	*sub;

	i = 0;
	len2 = ft_strlen(s);
	if (start < len2)
	{
		while (s[start + i] && i < len)
			i++;
	}
	sub = (char *)malloc(sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	if (start < len2)
	{
		while (s[start + i] && i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = 0;
	return (sub);
}
