/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:19:11 by cheseo            #+#    #+#             */
/*   Updated: 2022/07/21 18:18:21 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_intdigit(long nbr)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
		nbr *= -1;
	else if (nbr == 0)
		return (1);
	while (nbr > 9)
	{
		nbr /= 10;
		len *= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	digit;
	long	nbr;
	char	c;

	nbr = n;
	digit = ft_intdigit(nbr);
	if (nbr == 0)
		write(fd, "0", 1);
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(fd, "-", 1);
		}
		while (digit > 0)
		{
			c = nbr / digit + '0';
			write(fd, &c, 1);
			nbr %= digit;
			digit /= 10;
		}
	}
}
