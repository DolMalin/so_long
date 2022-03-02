/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:40 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 16:16:26 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_init(t_img *img)
{
	if (!img->wall)
		puterr_exit("Can't open wall texture");
	if (!img->empty)
		puterr_exit("Can't open floor texture");
	if (!img->player)
		puterr_exit("Can't open player sprite");
	if (!img->collectible)
		puterr_exit("Can't open collectible texture");
	if (!img->exit)
		puterr_exit("Can't open exit texture");
}

t_img	*init_img(t_data *data)
{
	t_img	*output;
	int		w;
	int		h;
	char	*s;

	output = malloc(sizeof(t_img));
	if (!output)
		puterr_exit("Couldn't allocate memory while initializing images");
	s = WALL_PATH;
	output->wall = mlx_xpm_file_to_image(data->mlx, s, &w, &h);
	s = EMPTY_PATH;
	output->empty = mlx_xpm_file_to_image(data->mlx, s, &w, &h);
	s = PLAYER_PATH;
	output->player = mlx_xpm_file_to_image(data->mlx, s, &w, &h);
	s = COLLECTIBLE_PATH;
	output->collectible = mlx_xpm_file_to_image(data->mlx, s, &w, &h);
	s = EXIT_PATH;
	output->exit = mlx_xpm_file_to_image(data->mlx, s, &w, &h);
	check_init(output);
	return (output);
}
