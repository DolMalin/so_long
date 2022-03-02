/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:20:10 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 13:21:03 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_data	*fill_map(int fd, t_data *data)
{
	char	*buff;
	char	*temp;
	char	*flat_map;

	while (true)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		if (flat_map == NULL)
			flat_map = ft_strdup(buff);
		else
		{
			temp = flat_map;
			flat_map = ft_strjoin(temp, buff);
			free(temp);
		}
		free(buff);
	}
	data->map = ft_split(flat_map, '\n');
	free(flat_map);
	return (data);
}

static size_t	get_ymax(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	cmax_count(t_data *data)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			if (data->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_data	*init_data(char **av)
{
	int		fd;
	t_data	*data;
	t_data	*output;

	fd = open(av[1], O_RDONLY);
	data = malloc(sizeof(t_data));
	if (!data || fd == -1)
		puterr_exit("Error while initializing the map\n");
	data->mv_count = 0;
	data->c_count = 0;
	output = fill_map(fd, data);
	output->x_max = ft_strlen(data->map[0]);
	output->y_max = get_ymax(data->map);
	output->cmax_count = cmax_count(data);
	output->on_exit = false;
	return (output);
}
