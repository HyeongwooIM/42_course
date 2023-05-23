/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:58:41 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/19 16:33:57 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_point(char *src)
{
	int	cnt;

	cnt = 0;
	while (*src)
	{
		if (*src == '.')
			cnt++;
		src++;
	}
	return (cnt);
}

static int	pre_process(char **src, int *sign)
{
	if (!*src)
		return (-1);
	if (count_point(*src) > 1)
		return (-1);
	if (**src == '-')
	{
		(*src)++;
		*sign = -1;
	}
	return (0);
}

static double	decimal_point(double base, int exponent)
{
	double	result;
	int		i;

	i = 1;
	result = 1;
	while (i <= exponent)
	{
		result = result * base;
		i++;
	}
	return (result);
}

int	ft_atod(char *src, double *num)
{
	int			i;
	int			sign;
	int			pointer;

	i = 1;
	sign = 1;
	*num = 0;
	pointer = 0;
	if (pre_process(&src, &sign))
		return (-1);
	while (*src && *src != '\n')
	{
		if (!pointer && ft_isdigit(*src))
			*num = (*num * 10) + (*src - '0');
		else if (*src == '.')
			pointer = 1;
		else if (pointer && ft_isdigit(*src))
			*num = (*src - '0') * decimal_point(0.1, i++) + *num;
		else
			return (-1);
		src++;
	}
	*num *= sign;
	return (0);
}
