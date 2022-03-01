/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:52:52 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 14:50:06 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exec_action(int key, t_data *data)
{
	update_user_pos(&data);
	if (key == KEY_U)
		move_up(&data);
	else if (key == KEY_D)
		move_down(&data);
	else if (key == KEY_L)
		move_left(&data);
	else if (key == KEY_R)
		move_right(&data);
	else if (key == KEY_ESC)
		exit_program(data);
	put_img(data, data->img, &data->mlx, &data->mlx_win);
	return (0);
}
