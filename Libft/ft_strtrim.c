/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:09:36 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/17 19:51:21 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	is_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	len_malloc(const char *s1, const char *set)
{
	int	i;
	int	len;
	int	len2;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (is_in(s1[i], set) && i < len)
		i++;
	if (i == len)
		return (0);
	len2 = len;
	while (is_in(s1[len - 1], set) && len > 1)
	{
		len--;
		i++;
	}
	return (len2 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*trimmed;

	i = 0;
	j = 0;
	len = len_malloc(s1, set);
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	if (len)
	{
		while (is_in(s1[i], set))
			i++;
		while (j < len)
		{
			trimmed[j] = s1[i];
			i++;
			j++;
		}
	}
	trimmed[j] = 0;
	return (trimmed);
}
