/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:06:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 07:26:40 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_data *data)
{
	if (data->y == 0 || data->y == data->map_heigth - 1
		|| data->x == 0 || data->x == data->map_width - 1)
		ft_error();
}

void	ft_calculate_map_size(t_data *data, char *path)
{
	char	*read;
	int		fd;

	data->map_heigth = 0;
	fd = open(path, O_RDONLY);
	read = get_next_line(fd);
	data->map_width = ft_strlen(read) - 1;
	while (read)
	{
		data->map_heigth++;
		free(read);
		read = get_next_line(fd);
	}
	free(read);
}

void	ft_get_map(t_data *data, char *path)
{
	int		fd;
	int		i;

	data->path = path;
	data->map = malloc(sizeof(char *) * data->map_heigth);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < data->map_heigth)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
}

static void	ft_init_map(t_data *data, t_map *map)
{
	int	a;

	a = 64;
	map->floor = mlx_xpm_file_to_image(data->mlx, "./srcs/floor.xpm", &a, &a);
	map->wall = mlx_xpm_file_to_image(data->mlx, "./srcs/wall.xpm", &a, &a);
	map->exit = mlx_xpm_file_to_image(data->mlx, "./srcs/exit.xpm", &a, &a);
}

void	ft_put_map(t_data *data)
{
	t_map	map;

	ft_init_map(data, &map);
	while (data->y < data->map_heigth)
	{
		data->x = 0;
		while (data->x < data->map_width)
		{
			if (data->map[data->y][data->x] == '1')
				mlx_put_image_to_window(data->mlx,
					data->win, map.wall, data->x * 64, data->y * 64);
			else
			{
				ft_check_walls(data);
				mlx_put_image_to_window(data->mlx, data->win,
					map.floor, data->x * 64, data->y * 64);
			}
			if (data->map[data->y][data->x] == 'E')
				mlx_put_image_to_window(data->mlx,
					data->win, map.exit, data->x * 64, data->y * 64);
			data->x++;
		}
		data->y++;
	}
}
