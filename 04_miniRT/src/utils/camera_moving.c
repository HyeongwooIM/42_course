/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:02:14 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/23 12:31:19 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "utils.h"

void	safe_change_dir(t_vector *dir, t_vector change_dir)
{
	*dir = vplus(*dir, change_dir);
	if (dir->x == 0 && dir->y == 0 && dir->z == 0)
		*dir = vplus(*dir, change_dir);
	if (dir->x > 1)
		dir->x = 1;
	if (dir->y > 1)
		dir->y = 1;
	if (dir->z > 1)
		dir->z = 1;
	if (dir->x < -1)
		dir->x = -1;
	if (dir->y < -1)
		dir->y = -1;
	if (dir->z < -1)
		dir->z = -1;
}

int	camera_rotate(int keycode, t_scene *scene)
{
	if (keycode == ARROW_U)
		safe_change_dir(&scene->camera.dir, vec3(0.2, 0, 0));
	else if (keycode == ARROW_D)
		safe_change_dir(&scene->camera.dir, vec3(-0.2, 0, 0));
	else if (keycode == ARROW_L)
		safe_change_dir(&scene->camera.dir, vec3(0, -0.2, 0));
	else if (keycode == ARROW_R)
		safe_change_dir(&scene->camera.dir, vec3(0, 0.2, 0));
	else if (keycode == KEY_COMMA)
		safe_change_dir(&scene->camera.dir, vec3(0, 0, 0.2));
	else if (keycode == KEY_DOT)
		safe_change_dir(&scene->camera.dir, vec3(0, 0, -0.2));
	else
		return (FALSE);
	return (TRUE);
}

int	camera_moving(int keycode, t_scene *scene)
{
	t_vector	dir;
	t_vector	right;
	t_vector	up;

	dir = scene->camera.dir;
	up = scene->camera.up_normal;
	right = scene->camera.right_normal;
	if (keycode == KEY_D)
		scene->camera.coord = vplus(scene->camera.coord, right);
	else if (keycode == KEY_A)
		scene->camera.coord = vminus(scene->camera.coord, right);
	else if (keycode == KEY_E)
		scene->camera.coord = vplus(scene->camera.coord, up);
	else if (keycode == KEY_Q)
		scene->camera.coord = vminus(scene->camera.coord, up);
	else if (keycode == KEY_W)
		scene->camera.coord = vplus(scene->camera.coord, dir);
	else if (keycode == KEY_S)
		scene->camera.coord = vminus(scene->camera.coord, dir);
	else
	{
		if (!camera_rotate(keycode, scene))
			return (FALSE);
	}
	return (TRUE);
}
