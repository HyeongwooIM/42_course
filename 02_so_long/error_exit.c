/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:27:13 by him               #+#    #+#             */
/*   Updated: 2022/10/20 12:33:45 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

// void	free_map(t_param *param)
// {
// 	t_map	*temp;
// 	t_map	*map;

// 	map = param->map;
// 	while (map)
// 	{
// 		temp = map->next;
// 		free(map->line);
// 		free(map);
// 		map = temp;
// 	}
// 	free(map);
// }
