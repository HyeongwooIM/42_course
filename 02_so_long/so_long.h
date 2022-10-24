/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:17:06 by him               #+#    #+#             */
/*   Updated: 2022/10/24 16:16:21 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define PRESS_RED_BUTTON	17

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}t_map;

typedef struct s_param
{
	t_map	*map;
	char	*map_name;
	int		fd;
	int		img_height;
	int		win_height;
	int		img_width;
	int		win_width;
	size_t	e_num;
	size_t	p_num;
	size_t	c_num;
	size_t	x;
	size_t	y;
	int		move_count;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*g;
	void	*w;
	void	*p;
	void	*c;
	void	*e;
}t_param;

void	create_map(t_param *param);
void	get_player(t_param *param);
void	check_map(t_param *param);
void	middle_check(char *line);
void	top_bottom_check(char *line);
void	free_map(t_param *param);
void	get_map(t_param *param);
char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
int		key_function(int keycode, t_param *param);
int		esc_press(int keycode);
void	set_p(t_param *par);
int		get_e(t_param *param);
void	img_change(t_param *param, int keycode);
void	error_exit(char *str);

#endif
