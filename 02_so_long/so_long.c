/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:48:23 by him               #+#    #+#             */
/*   Updated: 2022/10/20 15:15:28 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_press(int keycode)
{
	if (keycode == KEY_ESC)
	{
		printf("exit");
		exit(0);
	}
	return (0);
}

int	red_button_press(void)
{
	printf("exit");
	exit (0);
	return (0);
}

void	set_param(t_param *param)
{
	param->fd = open(param->map_name, O_RDONLY);
	if (param->fd <= 0)
		error_exit("fd 확인 ");
	param->map = 0;
	param->e_num = 0;
	param->p_num = 0;
	param->c_num = 0;
	param->win_width = 0;
	param->win_height = 0;
	param->x = 0;
	param->y = 0;
	param->move_count = 0;
	param->mlx_ptr = mlx_init();
	param->g = mlx_xpm_file_to_image \
	(param->mlx_ptr, "img/ground.xpm", &param->img_width, &param->img_height);
	param->w = mlx_xpm_file_to_image \
	(param->mlx_ptr, "img/wall.xpm", &param->img_width, &param->img_height);
	param->c = mlx_xpm_file_to_image \
	(param->mlx_ptr, "img/collect.xpm", &param->img_width, &param->img_height);
	param->e = mlx_xpm_file_to_image \
	(param->mlx_ptr, "img/exit.xpm", &param->img_width, &param->img_height);
	param->p = mlx_xpm_file_to_image \
	(param->mlx_ptr, "img/down.xpm", &param->img_width, &param->img_height);
	param->win_ptr = NULL;
}

int	file_name_check(char *str)
{
	int	i;

	i = 0;
	while (*str)
		str++;
	str--;
	if (i == 0 && *str == 'r')
	{
		str--;
		i++;
	}
	if (i == 1 && *str == 'e')
	{
		str--;
		i++;
	}
	if (i == 2 && *str == 'b')
	{
		str--;
		i++;
	}
	if (i == 3 && *str == '.')
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (argc < 2 || file_name_check(argv[1]))
		error_exit("인자 확인");
	param.map_name = argv[1];
	param.img_height = 32;
	param.img_width = 32;
	set_param(&param);
	get_map(&param);
	check_map(&param);
	get_player(&param);
	param.win_ptr = mlx_new_window(param.mlx_ptr, \
	param.win_width, param.win_height, "so_long");
	create_map(&param);
	mlx_key_hook(param.win_ptr, &key_function, &param);
	mlx_hook(param.win_ptr, PRESS_RED_BUTTON, 0, &red_button_press, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
