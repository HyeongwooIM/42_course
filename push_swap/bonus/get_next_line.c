/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:01:34 by him               #+#    #+#             */
/*   Updated: 2022/10/06 21:03:08 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_backup_str(char *str)
{
	int		i;
	int		j;
	char	*backup;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	backup = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!backup)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		backup[j++] = str[i++];
	backup[j] = '\0';
	free(str);
	return (backup);
}

char	*ft_read_to_left_str(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(((size_t)8 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 8;
	while (!ft_strchr(str, '\n') && rd_bytes == 8)
	{
		rd_bytes = read(fd, buff, 8);
		if (rd_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		if (rd_bytes == 0)
			break ;
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0)
		return (0);
	str = ft_read_to_left_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_backup_str(str);
	return (line);
}
