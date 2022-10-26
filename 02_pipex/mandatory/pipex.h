/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:55:24 by him               #+#    #+#             */
/*   Updated: 2022/10/26 20:58:57 by woohyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../00_libft/libft.h"

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	*path;
}t_arg;

void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error_exit(char *str);

#endif