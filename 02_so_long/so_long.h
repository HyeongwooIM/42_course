/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:12:12 by him               #+#    #+#             */
/*   Updated: 2022/10/12 20:32:17 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "gnl/get_next_line.h"

typedef struct s_map
{
	char	*map_line;
	t_map	*next;
}t_map;

typedef struct s_param
{
	int		fd;
	t_map	*map;
}t_param;

#endif