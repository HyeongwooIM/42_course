/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:41:23 by him               #+#    #+#             */
/*   Updated: 2022/10/20 14:21:21 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_param *param, int y)
{
	t_map	*map;
	char	*str;

	map = param->map;
	while (y-- != 0)
		map = map->next;
	str = map->line;
	if (str[param->x - 1] == '1')
		return ;
	else if (str[param->x - 1] == 'E')
		if (get_e(param))
			return ;
	if (str[param->x - 1] == 'C')
		param->c_num--;
	str[param->x - 1] = 'P';
	str[param->x] = '0';
	param->move_count++;
	set_p(param);
}

void	move_right(t_param *param, int y)
{
	t_map	*map;
	char	*str;

	map = param->map;
	while (y-- != 0)
		map = map->next;
	str = map->line;
	if (str[param->x + 1] == '1')
		return ;
	else if (str[param->x + 1] == 'E')
		if (get_e(param))
			return ;
	if (str[param->x + 1] == 'C')
		param->c_num--;
	str[param->x + 1] = 'P';
	str[param->x] = '0';
	param->move_count++;
	set_p(param);
}

void	move_up(t_param *param, int y)
{
	t_map	*map;
	char	*str;

	map = param->map;
	str = map->line;
	while (y != 0)
	{
		if (y == 1)
		{
			if (str[param->x] == '1')
				return ;
			else if (str[param->x] == 'E')
				if (get_e(param))
					return ;
			if (str[param->x] == 'C')
				param->c_num--;
			str[param->x] = 'P';
		}
		map = map->next;
		str = map->line;
		y--;
	}
	str[param->x] = '0';
	param->move_count++;
	set_p(param);
}

void	move_down(t_param *param, int y)
{
	t_map	*map;
	char	*str;
	char	*savestr;

	map = param->map;
	while (y != 0)
	{
		map = map->next;
		y--;
	}
	savestr = map->line;
	map = map->next;
	str = map->line;
	if (str[param->x] == '1')
		return ;
	else if (str[param->x] == 'E')
		if (get_e(param))
			return ;
	if (str[param->x] == 'C')
		param->c_num--;
	str[param->x] = 'P';
	savestr[param->x] = '0';
	param->move_count++;
	set_p(param);
}

int	key_function(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		move_up(param, param->y);
	else if (keycode == KEY_S)
		move_down(param, param->y);
	else if (keycode == KEY_A)
		move_left(param, param->y);
	else if (keycode == KEY_D)
		move_right(param, param->y);
	else if (keycode == KEY_ESC)
		esc_press(keycode);
	img_change(param, keycode);
	create_map(param);
	printf("step : %d\n", param->move_count);
	return (0);
}
