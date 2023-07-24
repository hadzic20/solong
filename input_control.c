/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	exit_modes(int exit_mode)
{
	if (exit_mode == 0)
		perror("Error\n");
	if (exit_mode == 1)
		ft_printf("You left dude, come back...");
	if (exit_mode == 2)
		ft_printf("I am home with a ball of yarn!");
	if (exit_mode == 3)
		ft_printf("Error\nInvalid Map!");
	if (exit_mode == 4)
		ft_printf("Error\nCheck your folders, there isn't file for rendering.");
}

int	exit_game(t_data *data, int exit_mode)
{
	exit_modes(exit_mode);
	if (data->w_object != NULL)
		mlx_destroy_image(data->mlx, data->w_object);
	if (data->c_object != NULL)
		mlx_destroy_image(data->mlx, data->c_object);
	if (data->e_object != NULL)
		mlx_destroy_image(data->mlx, data->e_object);
	if (data->p_object != NULL)
		mlx_destroy_image(data->mlx, data->p_object);
	if (data->map != NULL)
		free_map(data->map);
	if (data->mapcopy != NULL)
		free_map(data->mapcopy);
	if (data->mlx_window != NULL)
		mlx_destroy_window(data->mlx, data->mlx_window);
	if (data != NULL)
		free(data);
	exit(exit_mode);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	key_event(int key, t_data *data)
{
	if (key == W)
		player_movement(data, data->x - 1, data->y);
	if (key == A)
		player_movement(data, data->x, data->y - 1);
	if (key == S)
		player_movement(data, data->x + 1, data->y);
	if (key == D)
		player_movement(data, data->x, data->y + 1);
	if (key == ESC)
		exit_game(data, 1);
	return (0);
}

void	player_movement(t_data *data, int x, int y)
{
	if (data->map[x][y] != '1' && data->map[x][y] != 'E')
	{
		if (data->map[x][y] == 'C' && data->c_size != data->c_count)
			data->c_count++;
		data->map[data->x][data->y] = '0';
		data->x = x;
		data->y = y;
		data->map[x][y] = 'P';
		data->moves++;
		render_map(data);
		ft_printf("Moves: %d \n", data->moves);
	}
	else if (data->c_size == data->c_count && \
			data->map[x][y] == 'E')
	{
		data->moves++;
		ft_printf("Moves: %d \n", data->moves);
		exit_game(data, 2);
	}
}
