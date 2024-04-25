/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:29:26 by picarlie          #+#    #+#             */
/*   Updated: 2024/04/24 19:00:44 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	atodbl(char *s)
{
	long	interger_part;
	double	fractional_part;
	double	pow;
	int		sign;

	interger_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		interger_part = (interger_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		pow = pow / 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((interger_part + fractional_part) * sign);
}
