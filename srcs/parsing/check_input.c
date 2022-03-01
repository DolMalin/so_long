/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:03:22 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/01 13:34:44 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_bool	check_file_is_dir(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_DIRECTORY);
	if (fd == -1)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

static t_bool	check_file_exists(const char *file_path)
{
	int	fd;
	int	ret;
	int	buffer[1];

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (false);
	}
	ret = read(fd, buffer, 1);
	if (ret < 1)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

static t_bool	check_extension(const char *file_path)
{
	size_t	i;

	i = ft_strlen(file_path) - 1;
	while (file_path[i] && file_path[i] != '.')
		i--;
	if (ft_strncmp(&file_path[i], ".ber", 5) != 0)
		return (false);
	return (true);
}

void	check_input(int ac, char **av)
{
	int	arg_len;

	if (ac != 2)
		puterr_exit("Too or few arguments\n");
	arg_len = ft_strlen(av[1]);
	if (check_file_is_dir(av[1]))
		puterr_exit("File is a directory\n");
	if (arg_len < 1 || !check_extension(av[1]) || !check_file_exists(av[1]))
		puterr_exit("Invalid file, path or extension\n");
}
