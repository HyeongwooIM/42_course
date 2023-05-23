/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:48:30 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/20 17:24:49 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

enum	e_err_status
{
	AC_ERR,
	AR_ERR,
	SCENE_ERR
};

int	error_print(int err);

#endif