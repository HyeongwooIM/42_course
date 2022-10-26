/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:27:48 by him               #+#    #+#             */
/*   Updated: 2022/07/19 15:53:01 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src || n == 0)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dst);
}
