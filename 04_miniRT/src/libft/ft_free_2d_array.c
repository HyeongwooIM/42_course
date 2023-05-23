/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheseo <cheseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:13:13 by cheseo            #+#    #+#             */
/*   Updated: 2023/05/08 19:55:21 by cheseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_free_2d_array(char **res)
{
	size_t	idx;

	idx = 0;
	while (res[idx])
	{
		free(res[idx]);
		idx++;
	}
	free(res);
	return (NULL);
}
