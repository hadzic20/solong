/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:28:31 by ahadzic           #+#    #+#             */
/*   Updated: 2022/12/17 17:40:03 by ahadzic          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	get_line_count(t_data *data)
{
	char	c;
	int		line_count;
	int		fd;

	fd = open(data->map_destination, O_RDONLY);
	if (fd < 0)
		exit_game(data, 0);
	line_count = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			line_count++;
	}
	close(fd);
	return (line_count + 1);
}

int	get_line_size(t_data *data)
{
	char	c;
	int		line_size;
	int		fd;

	fd = open(data->map_destination, O_RDONLY);
	if (fd < 0)
		exit_game(data, 0);
	line_size = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		line_size++;
	}
	close(fd);
	return (line_size);
}

int	get_file_length(t_data *data)
{
	char	c;
	int		length;
	int		fd;

	length = 0;
	fd = open(data->map_destination, O_RDONLY);
	if (fd < 0)
		exit_game(data, 0);
	while (read(fd, &c, 1))
		length++;
	close(fd);
	return (length);
}

void	set_initial_informations(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c_size += 1;
			else if (data->map[i][j] == 'E')
				data->e_count += 1;
			else if (data->map[i][j] == 'P')
			{
				data->spawn_count += 1;
				data->x = i;
				data->y = j;
			}
			else if (data->map[i][j] != '0' && data->map[i][j] != '1')
				exit_game(data, 3);
			j++;
		}
		i++;
	}
}

void	read_map(t_data *data)
{
	int		fd;
	int		file_length;
	char	*map;

	file_length = get_file_length(data);
	map = (char *)malloc(file_length + 1);
	if (!map)
		exit_game(data, 0);
	fd = open(data->map_destination, O_RDONLY);
	if (fd < 0)
		exit_game(data, 0);
	read(fd, map, file_length);
	map[file_length] = '\0';
	data->map = ft_split(map, '\n');
	data->mapcopy = ft_split(map, '\n');
	set_initial_informations(data);
	close(fd);
	free(map);
}
