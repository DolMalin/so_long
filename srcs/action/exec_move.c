/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:25:27 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 15:44:31 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	exec_move(t_data **data, char *player_pos, char *dest_pos)
{
	*player_pos = '0';
	if (*dest_pos == 'E' && (*data)->c_count == (*data)->cmax_count)
	{
		*dest_pos = 'E';
		(*data)->mv_count++;
		print_move((*data)->mv_count);
		exit_program(*data);
	}
	else if ((*data)->on_exit == true)
	{
		*player_pos = 'E';
		(*data)->on_exit = false;
	}
	else if (*dest_pos == 'E')
		(*data)->on_exit = true;
	else if (*dest_pos == 'C')
			(*data)->c_count++;
	(*data)->mv_count++;
	*dest_pos = 'P';
}
