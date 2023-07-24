/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  instantiate_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	instantiate_world(t_data *data, int x, int y, char object)
{
	if (object == '1')
		instantiate_wall(data, x, y);
	if (object == 'P')
		instantiate_player(data, x, y);
	if (object == 'C')
		instantiate_collectible(data, x, y);
	if (object == 'E')
		instantiate_exit(data, x, y);
}

void	instantiate_wall(t_data *data, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "./textures/walls/ice.xpm", \
		&data->image_size, &data->image_size);
	if (img == NULL)
		exit_game(data, 11);
	else
	{
		data->w_object = img;
		mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
	}
}

void	instantiate_collectible(t_data *data, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "./textures/collectibles/yarn.xpm", \
		&data->image_size, &data->image_size);
	if (img == NULL)
		exit_game(data, 11);
	else
	{
		data->c_object = img;
		mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
	}
}

void	instantiate_exit(t_data *data, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "./textures/exits/home.xpm", \
		&data->image_size, &data->image_size);
	if (img == NULL)
		exit_game(data, 11);
	else
	{
		data->e_object = img;
		mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
	}
}

void	instantiate_player(t_data *data, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, "./textures/player/cat.xpm", \
		&data->image_size, &data->image_size);
	if (img == NULL)
		exit_game(data, 11);
	else
	{
		data->p_object = img;
		mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
	}
}
