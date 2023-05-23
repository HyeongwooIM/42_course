/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:52:15 by him               #+#    #+#             */
/*   Updated: 2023/05/19 16:33:57 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	vlength2(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vlength(t_vector vec)
{
	return (sqrt(vlength2(vec)));
}

t_vector	vplus(t_vector vec, t_vector vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}

t_vector	vplus_(t_vector vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

t_vector	vminus(t_vector vec, t_vector vec2)
{
	vec.x -= vec2.x;
	vec.y -= vec2.y;
	vec.z -= vec2.z;
	return (vec);
}
