/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:06:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/16 14:39:15 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	data->map = malloc(sizeof(char *) * data->map_heigth);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < data->map_heigth)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
}

void	ft_init_map(t_data *data, t_map *map)
{
	int	a;

	a = 64;
	map->floor = mlx_xpm_file_to_image(data->mlx, "./srcs/floor.xpm", &a, &a);
	map->wall = mlx_xpm_file_to_image(data->mlx, "./srcs/wall.xpm", &a, &a);
	map->collect = mlx_xpm_file_to_image(data->mlx, "./srcs/collect.xpm", &a, &a);
	map->player = mlx_xpm_file_to_image(data->mlx, "./srcs/player.xpm", &a, &a);
}

void	ft_put_map(t_data *data)
{
	t_map	map;

	ft_init_map(data, &map);
	while (data->x < data->map_heigth)
	{
		data->y = 0;
		while (data->y < data->map_width)
		{
			if (data->map[data->x][data->y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, map.wall, data->y*64, data->x*64);
			else if (data->map[data->x][data->y] == '0')
				mlx_put_image_to_window(data->mlx, data->win, map.floor, data->y*64, data->x*64);
			else
			{
				mlx_put_image_to_window(data->mlx, data->win, map.floor, data->y*64, data->x*64);
				if (data->map[data->x][data->y] == 'P')
					mlx_put_image_to_window(data->mlx, data->win, map.player, data->y*64, data->x*64);
				else if (data->map[data->x][data->y] == 'C')
					mlx_put_image_to_window(data->mlx, data->win, map.collect, data->y*64, data->x*64);
			}
			data->y++;
		}
		data->x++;
	}
}