/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:55:24 by him               #+#    #+#             */
/*   Updated: 2022/10/25 17:38:13 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	*path;
}t_arg;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif