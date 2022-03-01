/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:38:26 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 13:38:27 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(void **mlx, void **mlx_win, t_data *data)
{
	int	x;
	int	y;

	if (data->x_max <= WIDTH)
		x = data->x_max * 100;
	else
		x = WIDTH * 100;
	if (data->y_max <= HEIGHT)
		y = data->y_max * 100;
	else
		y = HEIGHT * 100;
	*mlx = mlx_init();
	*mlx_win = mlx_new_window(*mlx, x, y, "SO_LONG");
}
