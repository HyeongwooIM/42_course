/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:54:56 by him               #+#    #+#             */
/*   Updated: 2022/10/24 20:07:45 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 0 || !*argv)
		return (1);
	pid = fork();
	if (pid == 0)
		printf("1\n");
	if (pid == 1)
		printf("2\n");
	return (0);
}
