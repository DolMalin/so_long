/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:57:44 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 15:52:11 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_move(int nb)
{
	ft_putstr_fd("\rMoves : ", 1);
	ft_putnbr_fd(nb, 1);
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
	print_move((*data)->mv_count);
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
	print_move((*data)->mv_count);
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
	print_move((*data)->mv_count);
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
	print_move((*data)->mv_count);
}
