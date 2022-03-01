/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:03:19 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 15:29:09 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	clear_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->empty);
	mlx_destroy_image(data->mlx, data->img->player);
	mlx_destroy_image(data->mlx, data->img->exit);
	mlx_destroy_image(data->mlx, data->img->collectible);
	free(data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data);
}
