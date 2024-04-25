/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:36:17 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/24 16:23:15 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*answer;

	i = 0;
	c = (char)c;
	while (s[i] && c != s[i])
		i++;
	if (c && !s[i])
		return (NULL);
	answer = (char *)&s[i];
	return (answer);
}
