/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	validate(t_data *data)
{
	check_extension(data);
	check_map(data);
	flood_fill(data, data->x, data->y);
	last_control(data);
	if (data->spawn_count != 1)
		exit_game(data, 3);
	if (data->c_size == 0)
		exit_game(data, 3);
	if (data->e_count == 0)
		exit_game(data, 3);
}

void	check_extension(t_data *data)
{	
	int		i;

	i = 0;
	while (data->map_destination[i] != '\0')
		i++;
	if (data->map_destination[i - 4] != '.')
		exit_game(data, 3);
	if (data->map_destination[i - 3] != 'b')
		exit_game(data, 3);
	if (data->map_destination[i - 2] != 'e')
		exit_game(data, 3);
	if (data->map_destination[i - 1] != 'r')
		exit_game(data, 3);
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i == 0 || i == get_line_count(data) - 1 || \
				j == 0 || j == get_line_size(data) - 1)
				if (data->map[i][j] != '1')
					exit_game(data, 3);
			j++;
		}
		if (get_line_size(data) - 1 != j - 1)
			exit_game(data, 3);
		i++;
	}
}

void	flood_fill(t_data *data, int x, int y)
{
	if (data->x < 0 || data->x >= get_line_count(data) || \
	data->y < 0 || data->y >= get_line_size(data))
		return ;
	if (data->mapcopy[x][y] == 'E')
		data->mapcopy[x][y] = '1';
	if (data->mapcopy[x][y] == '1')
		return ;
	data->mapcopy[x][y] = '1';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

void	last_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->mapcopy[i])
	{
		j = 0;
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'C' || \
			data->mapcopy[i][j] == 'E')
				exit_game(data, 3);
			j++;
		}
		i++;
	}
}
