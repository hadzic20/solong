/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/mlx/mlx.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

enum	e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
};

typedef struct s_data
{
	void	*mlx;
	void	*mlx_window;
	char	**map;
	char	**mapcopy;
	void	*w_object;
	void	*c_object;
	void	*e_object;
	void	*p_object;
	char	*map_destination;
	int		x;
	int		y;
	int		image_size;
	int		c_count;
	int		c_size;
	int		spawn_count;
	int		e_count;
	int		moves;
}	t_data;

void	exit_modes(int exit_mode);
int		exit_game(t_data *data, int exit_mode);
int		key_event(int key, t_data *data);
void	instantiate_wall(t_data *data, int x, int y);
void	instantiate_collectible(t_data *data, int x, int y);
void	instantiate_exit(t_data *data, int x, int y);
void	instantiate_player(t_data *data, int x, int y);
void	data_init(t_data *data);
void	player_movement(t_data *data, int current_x, int current_y);
void	free_map(char **map);
int		get_line_count(t_data *data);
int		get_line_size(t_data *data);
int		get_file_length(t_data *data);
void	set_initial_informations(t_data *data);
void	read_map(t_data *data);
void	instantiate_world(t_data *data, int x, int y, char object);
void	render_map(t_data *data);
void	validate(t_data *data);
void	check_extension(t_data *data);
void	check_map(t_data *data);
void	flood_fill(t_data *data, int x, int y);
void	last_control(t_data *data);
#endif