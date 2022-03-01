/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:47:47 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 13:47:48 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*get_img(char c, t_img *img)
{
	if (c == '1')
		return (img->wall);
	if (c == '0')
		return (img->empty);
	if (c == 'P')
		return (img->player);
	if (c == 'E')
		return (img->exit);
	if (c == 'C')
		return (img->collectible);
	return (NULL);
}
