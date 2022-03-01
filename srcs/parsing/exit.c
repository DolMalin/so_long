/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:04:50 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 15:17:40 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	puterr_exit(const char *msg)
{
	ft_putstr_fd("💥 ERROR : ", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	exit_program(t_data *data)
{
	ft_putstr_fd("Exit\n", 1);
	clear_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
