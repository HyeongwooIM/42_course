/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:02:06 by him               #+#    #+#             */
/*   Updated: 2022/07/19 15:17:28 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size < d_len + 1)
		return (s_len + size);
	while (d_len + 1 + i < size && src[i])
	{
		dst[i + d_len] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
