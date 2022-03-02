/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:43:24 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 15:39:07 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t	get_camx(t_data *data)
{
	if (data->x_max < WIDTH)
		return (0);
	if ((int)data->x - WIDTH / 2 <= 0)
		return (0);
	else if (data->x + WIDTH / 2 >= data->x_max)
		return (data->x_max - WIDTH);
	return (data->x - WIDTH / 2);
}

static size_t	get_camy(t_data *data)
{
	if (data->y_max < HEIGHT)
		return (0);
	if ((int)data->y - HEIGHT / 2 <= 0)
		return (0);
	else if (data->y + HEIGHT / 2 >= data->y_max)
		return (data->y_max - HEIGHT);
	return (data->y - HEIGHT / 2);
}

void	put_img(t_data *data, t_img *img, void **mlx, void **mlx_win)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	void	*t;

	update_user_pos(&data);
	i = 0;
	while (i < HEIGHT && i < data->y_max)
	{
		j = 0;
		while (j < WIDTH && j < data->x_max)
		{
			y = get_camy(data) + i;
			x = get_camx(data) + j;
			t = img->empty;
			if (data->map[y][x] == 'P' && data->on_exit)
				t = img->exit;
			mlx_put_image_to_window(*mlx, *mlx_win, t, j * 100, i * 100);
			t = get_img(data->map[y][x], img);
			mlx_put_image_to_window(*mlx, *mlx_win, t, j * 100, i * 100);
			j++;
		}
		i++;
	}
}
