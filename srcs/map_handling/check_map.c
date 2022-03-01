/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:28:42 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 13:30:25 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_bool	check_map_only_chars(t_data *data, const char *charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			if (!is_in_charset(data->map[i][j], charset))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static t_bool	check_map_all_chars(t_data *data, const char *charset)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			if (data->map[i][j] == charset[count])
			{
				count++;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
	if (count == ft_strlen(charset))
		return (true);
	return (false);
}

static t_bool	check_map_border(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			if ((i == 0 || i == data->y_max - 1) && data->map[i][j] != '1')
				return (false);
			if ((j == 0 || j == data->x_max - 1) && data->map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static t_bool	check_map_is_rectangular(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->y_max)
	{
		if (ft_strlen(data->map[i]) != data->x_max)
			return (false);
		i++;
	}
	return (true);
}

void	check_map(t_data *data)
{
	if (!check_map_only_chars(data, "01CEP"))
		puterr_exit("Map contains unvalid chars\n");
	else if (!check_map_all_chars(data, "1CEP"))
		puterr_exit("Map do not contains all the required chars\n");
	else if (!check_map_border(data))
		puterr_exit("Unvalid map border\n");
	else if (!check_map_is_rectangular(data))
		puterr_exit("Map is not rectangular\n");
}
