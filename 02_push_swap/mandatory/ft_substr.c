/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:35:06 by him               #+#    #+#             */
/*   Updated: 2022/10/07 11:37:24 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*arr;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < len)
		arr = (char *)ft_calloc(len_s + 1, sizeof(char));
	else
		arr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!arr)
		return (0);
	i = 0;
	while (i < len && start + i < len_s)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
