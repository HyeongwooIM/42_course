/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:56:13 by cheseo            #+#    #+#             */
/*   Updated: 2022/07/19 16:22:54 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*tmp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < (len1 + len2))
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
