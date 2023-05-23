/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: him <him@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:38:30 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/19 16:43:30 by him              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_error.h"
#include "libft.h"

int	error_print(int err)
{
	printf("Error\n");
	if (err == AC_ERR)
		ft_putstr_fd("Too many argument. Only 1 argument accepted.\n", 2);
	else if (err == AR_ERR)
		ft_putstr_fd(
			"Wrong file extension. Extension should be in [*.rt] form.\n", 2);
	else if (err == SCENE_ERR)
		ft_putstr_fd("Invalid input.\n", 2);
	return (-1);
}
