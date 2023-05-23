/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:48:05 by cheseo            #+#    #+#             */
/*   Updated: 2023/03/24 22:38:26 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	skip_until_num(const char *str, int *sign)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	my_atoi(const char *str, int *res)
{
	size_t	i;
	int		sign;

	if (!str || !res)
		return (-1);
	sign = 1;
	i = skip_until_num(str, &sign);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (*res >= INT_MAX / 10)
		{
			if ((sign < 0 && str[i] > '8') || (sign > 0 && str[i] > '7'))
				return (-1);
			else if (*res > INT_MAX / 10)
				return (-1);
		}
		*res = *res * 10 + (str[i++] - '0');
	}
	*res *= sign;
	return (0);
}
