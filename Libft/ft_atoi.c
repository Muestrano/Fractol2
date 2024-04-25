/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:32:37 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/16 17:23:41 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_return_value(char *str)
{
	int	i;
	int	value;

	i = 0;
	if (!str[i])
		return (0);
	value = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value = value + str[i] - 48;
		i++;
	}
	return (value);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		return_value;
	char	*nptr2;

	sign = 1;
	i = 0;
	nptr2 = (char *)nptr;
	while (nptr2[i] == 32 || (nptr2[i] >= 9 && nptr2[i] <= 13))
		i++;
	if (nptr2[i] == '+' || nptr2[i] == '-')
	{
		if (nptr2[i] == '-')
			sign *= -1;
		i++;
	}
	return_value = sign * (ft_return_value(&nptr2[i]));
	return (return_value);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_atoi("   \n+--2147483647"));
	//printf("%d\n", ft_atoi(argv[argc - 1]));
	//printf("%d\n", ft_atoi(argv[argc - 2]));
	return (0);
}*/