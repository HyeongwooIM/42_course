/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:58:26 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/04 17:05:44 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static size_t	ft_count_word(char const *s, char *charset)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]) && s[i])
			i++;
		cnt++;
		while (!ft_strchr(charset, s[i]) && s[i])
			i++;
	}
	return (cnt);
}

static char	*ft_strcpy(const char *str, char *charset, int len)
{
	int		j;
	char	*dest;

	while (ft_strchr(charset, *str))
		str++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < len)
		dest[j++] = *str++;
	dest[j] = '\0';
	return (dest);
}

char	**ft_strcpy_to_arr(char const *s, char *charset, char **res)
{
	int			idx;
	char const	*start;

	idx = 0;
	while (*s)
	{
		while (ft_strchr(charset, *s))
			s++;
		start = s;
		while (!ft_strchr(charset, *s))
			s++;
		res[idx] = ft_strcpy(start, charset, s - start);
		idx++;
	}
	return (res);
}

char	**ft_split_charset(char const *s, char *charset)
{
	int		word_cnt;
	char	**res;

	if (!s)
		return (NULL);
	word_cnt = ft_count_word(s, charset);
	res = malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	res[word_cnt] = NULL;
	res = ft_strcpy_to_arr(s, charset, res);
	if (!res)
		return (NULL);
	return (res);
}
