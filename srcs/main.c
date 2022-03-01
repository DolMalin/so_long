/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:58:43 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 16:04:08 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = init_data(av);
	check_map(data);
	init_window(&data->mlx, &data->mlx_win, data);
	data->img = init_img(data);
	run_game(data, data->img);
	return (0);
}
