/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:21:52 by him               #+#    #+#             */
/*   Updated: 2022/07/19 16:08:46 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_word(char *s, char c)
{
	int	i;
	int	world_num;

	i = 0;
	world_num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(s[i]))
			break ;
		world_num++;
		while (s[i] != c && s[i])
			i++;
	}
	return (world_num);
}

char	**free_all(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		arr[j] = 0;
		j++;
	}
	free(arr);
	arr = 0;
	return (0);
}

int	world_len(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		world_num;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (0);
	world_num = check_word((char *)s, c);
	arr = (char **)ft_calloc(world_num + 1, sizeof(char *));
	if (!arr)
		return (0);
	while (world_num--)
	{
		while (*s == c && *s)
			s++;
		len = world_len((char *)s, c);
		arr[i] = ft_substr((char *)s, 0, len);
		if (!(arr[i]))
			return (free_all(arr, i));
		s += len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
