/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:44 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 16:03:05 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	exec_move(t_data **data, char *player_pos, char *dest_pos)
{
	if (*dest_pos == 'C')
	{
		*player_pos = '0';
		*dest_pos = 'P';
		(*data)->mv_count++;
		(*data)->c_count++;
	}
	else if (*dest_pos == 'E' && (*data)->c_count == (*data)->cmax_count)
	{
		*player_pos = '0';
		*dest_pos = 'E';
		(*data)->mv_count++;
		exit_program(*data);
	}
	else if (*dest_pos != 'E')
	{
		*player_pos = '0';
		*dest_pos = 'P';
		(*data)->mv_count++;
	}
}

void	move_up(t_data **data)
{
	int		pos_x;
	int		pos_y;
	char	*player_pos;
	char	*dest_pos;

	pos_x = (*data)->x;
	pos_y = (*data)->y;
	player_pos = &(*data)->map[pos_y][pos_x];
	dest_pos = &(*data)->map[pos_y - 1][pos_x];
	if (*dest_pos == '1')
		return ;
	exec_move(data, player_pos, dest_pos);
	printf("\rMoves : %d\n", (*data)->mv_count);
}

void	move_down(t_data **data)
{
	int		pos_x;
	int		pos_y;
	char	*player_pos;
	char	*dest_pos;

	pos_x = (*data)->x;
	pos_y = (*data)->y;
	player_pos = &(*data)->map[pos_y][pos_x];
	dest_pos = &(*data)->map[pos_y + 1][pos_x];
	if (*dest_pos == '1')
		return ;
	exec_move(data, player_pos, dest_pos);
	printf("\rMoves : %d\n", (*data)->mv_count);
}

void	move_left(t_data **data)
{
	int		pos_x;
	int		pos_y;
	char	*player_pos;
	char	*dest_pos;

	pos_x = (*data)->x;
	pos_y = (*data)->y;
	player_pos = &(*data)->map[pos_y][pos_x];
	dest_pos = &(*data)->map[pos_y][pos_x - 1];
	if (*dest_pos == '1')
		return ;
	exec_move(data, player_pos, dest_pos);
	printf("\rMoves : %d\n", (*data)->mv_count);
}

void	move_right(t_data **data)
{
	int		pos_x;
	int		pos_y;
	char	*player_pos;
	char	*dest_pos;

	pos_x = (*data)->x;
	pos_y = (*data)->y;
	player_pos = &(*data)->map[pos_y][pos_x];
	dest_pos = &(*data)->map[pos_y][pos_x + 1];
	if (*dest_pos == '1')
		return ;
	exec_move(data, player_pos, dest_pos);
	printf("\rMoves : %d\n", (*data)->mv_count);
}
