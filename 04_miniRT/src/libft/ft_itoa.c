/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:37:07 by cheseo            #+#    #+#             */
/*   Updated: 2022/07/21 18:16:24 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_intlen(long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len += 1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (++len);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	long	nbr;

	nbr = n;
	size = ft_intlen(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	str[size--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
