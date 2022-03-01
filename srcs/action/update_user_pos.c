/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_user_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:44:51 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 13:45:03 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_user_pos(t_data **data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (*data)->y_max)
	{
		j = 0;
		while (j < (*data)->x_max)
		{
			if ((*data)->map[i][j] == 'P')
			{
				(*data)->y = i;
				(*data)->x = j;
			}
			j++;
		}
		i++;
	}
}
