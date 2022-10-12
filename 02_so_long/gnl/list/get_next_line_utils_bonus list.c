/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:02:26 by him               #+#    #+#             */
/*   Updated: 2022/09/15 11:24:14 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*r_str;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';	
	}
	if (!str || !buff)
		return (NULL);
	r_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (r_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			r_str[i] = str[i];
	while (buff[j] != '\0')
		r_str[i++] = buff[j++];
	r_str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (r_str);
}

t_gnl_lst	*new_buff(int index)
{
	t_gnl_lst	*new;

	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->index = index;
	return (new);
}

t_gnl_lst	*find_buff(t_gnl_lst *lst_buff, int fd)
{
	t_gnl_lst	*new;
	int			index;

	index = 0;
	while (lst_buff)
	{
		if (lst_buff->index == fd)
			break ;
		if (lst_buff->next == NULL)
		{
			lst_buff->next = new_buff(index);
			if (!(lst_buff->next))
				return (0);
		}
		lst_buff = lst_buff->next;
		index++;
	}
	return (lst_buff);
}
