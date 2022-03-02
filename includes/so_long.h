/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:00:19 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/03/02 15:45:53 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ============== ~ INCLUDES ~ ============== */
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

/* ============== ~ STRUCTS ~ ============== */
typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*exit;
	void	*collectible;
}				t_img;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	size_t	x_max;
	size_t	y_max;
	size_t	x;
	size_t	y;
	int		mv_count;
	int		c_count;
	int		cmax_count;
	t_bool	on_exit;
}			t_data;

/* ============== ~ MAP CONFIG ~ ============== */
# define WIDTH 11
# define HEIGHT 7

/* ============== ~ SPRITES PATH ~ ============== */
# define WALL_PATH "./assets/sprites/wall1.xpm"
# define EMPTY_PATH "./assets/sprites/sol1.xpm"
# define PLAYER_PATH "./assets/sprites/perso.xpm"
# define EXIT_PATH "./assets/sprites/exit.xpm"
# define COLLECTIBLE_PATH "./assets/sprites/beer1.xpm"

/* ============== ~ KEY BINDING ~ ============== */
# define KEY_U 13
# define KEY_L 0
# define KEY_D 1
# define KEY_R 2
# define KEY_ESC 53

/* ============== ~ PARSING ~ ============== */
void	check_input(int ac, char **av);
void	puterr_exit(const char *msg);
int		exit_program(t_data *data);

/* ============== ~ MAP HANDLING ~ ============== */
t_data	*init_data(char **av);
void	check_map(t_data *data);
void	clear_data(t_data *data);
void	print_map(char **map);
t_bool	is_in_charset(char c, const char *charset);

/* ============== ~ GRAPHIC HANDLING ~ ============== */
void	init_window(void **mlx, void **mlx_win, t_data *data);
void	*get_img(char c, t_img *img);
void	put_img(t_data *data, t_img *img, void **mlx, void **mlx_win);
t_img	*init_img(t_data *data);
void	run_game(t_data *data, t_img *img);

/* ============== ~ ACTION ~ ============== */
void	update_user_pos(t_data **data);
void	print_move(int nb);
void	move_up(t_data **data);
void	move_down(t_data **data);
void	move_left(t_data **data);
void	move_right(t_data **data);
int		exec_action(int key, t_data *data);
void	exec_move(t_data **data, char *player_pos, char *dest_pos);

#endif