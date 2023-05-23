/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:53:56 by cheseo            #+#    #+#             */
/*   Updated: 2022/07/18 11:43:55 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp;
	char const	*str;

	i = 0;
	tmp = dst;
	str = src;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (len-- > 0)
			tmp[len] = str[len];
	else
	{
		while (i < len)
		{
			tmp[i] = str[i];
			i++;
		}
	}
	return (dst);
}
