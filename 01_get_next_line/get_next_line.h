/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:02:53 by him               #+#    #+#             */
/*   Updated: 2022/09/15 15:03:15 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE=1000
# endif

char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);

#endif
