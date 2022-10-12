/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:01:34 by him               #+#    #+#             */
/*   Updated: 2022/09/15 13:12:03 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	buff = malloc(((ssize_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = BUFFER_SIZE;
	while (!ft_strchr(str, '\n') && rd_bytes == BUFFER_SIZE)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
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
	t_gnl_lst			*line;
	static t_gnl_lst	*head;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	head = ft_read_to_left_str(fd, head);
	if (!head)
		return (NULL);
	line = ft_get_line(head);
	head = ft_backup_str(head);
	return (line);
}
