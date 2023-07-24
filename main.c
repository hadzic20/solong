/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	render_map(t_data *data)
{	
	int	i;
	int	j;
	int	x;
	int	y;

	mlx_clear_window(data->mlx, data->mlx_window);
	i = 0;
	y = 0;
	while (data -> map[i])
	{
		j = 0;
		x = 0;
		while (data -> map[i][j])
		{
			instantiate_world(data, x, y, data -> map[i][j]);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

void	data_init(t_data *data)
{
	data->p_object = NULL;
	data->w_object = NULL;
	data->c_object = NULL;
	data->e_object = NULL;
	data->mlx = NULL;
	data->map = NULL;
	data->mapcopy = NULL;
	data->mlx_window = NULL;
	data->x = 0;
	data->y = 0;
	data->image_size = 0;
	data->c_size = 0;
	data->c_count = 0;
	data->moves = 0;
	data->spawn_count = 0;
	data->e_count = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		perror("Error\n");
	data_init(data);
	if (argc != 2)
		exit_game(data, 0);
	data->map_destination = argv[1];
	read_map(data);
	validate(data);
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, \
		64 * get_line_size(data), 64 * get_line_count(data), "CatWalk");
	render_map(data);
	ft_printf("Moves: %d \n", data->moves);
	mlx_hook(data->mlx_window, 2, 1L << 0, key_event, data);
	mlx_hook(data->mlx_window, 17, 1L << 17, exit_game, data);
	mlx_loop(data->mlx);
	return (0);
}
