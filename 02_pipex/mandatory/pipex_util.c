/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:07:14 by him               #+#    #+#             */
/*   Updated: 2022/10/25 14:07:27 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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