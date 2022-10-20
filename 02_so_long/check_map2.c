/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:23:40 by him               #+#    #+#             */
/*   Updated: 2022/10/20 12:42:48 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_bottom_check(char *line)
{
	while (*line != '\n' && *line != '\0')
	{
		if (*line != '1')
			error_exit("벽이 올바르지 않습니다.");
		line++;
	}
}

void	middle_check(char *line)
{
	if (*line != '1')
		error_exit("벽이 올바르지 않습니다.");
	while (*line != '\n' && *line != '\0')
		line++;
	line--;
	if (*line != '1')
		error_exit("벽이 올바르지 않습니다.");
}
