/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:30:22 by him               #+#    #+#             */
/*   Updated: 2022/07/19 15:36:39 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	hlen;
	size_t	nlen;

	if (!*needle)
		return ((char *)haystack);
	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	i = 0;
	if (hlen < nlen || len < nlen)
		return (0);
	while (i + nlen <= len)
	{
		if (haystack[i] == *needle && !ft_strncmp(haystack + i, needle, nlen))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
