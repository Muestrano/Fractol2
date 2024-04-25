/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:57:24 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/16 18:53:22 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

/*
static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;
	char	*s4;
	char	*s5;

	s4 = (char *)s1;
	s5 = (char *)s2;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s4) + ft_strlen(s5) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s4[i])
	{
		s3[i] = s4[i];
		i++;
	}
	j = 0;
	while (s5[j])
	{
		s3[i + j] = s5[j];
		j++;
	}
	s3[i + j] = 0;
	return (s3);
}
