/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:03:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:00:36 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_player(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_heigth)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'P')
			{
				player->y = i;
				player->x = j;
				mlx_put_image_to_window(data->mlx,
					data->win, player->stand, player->x * 64, player->y * 64);
			}
			j++;
		}
		i++;
	}
}

void	ft_init_player(t_data *data, t_player *player)
{
	int	a;

	a = 64;
	player->count = 0;
	player->front_1 = mlx_xpm_file_to_image(data->mlx,
			"./srcs/cat_front_1.xpm", &a, &a);
	player->back_1 = mlx_xpm_file_to_image(data->mlx,
			"./srcs/cat_back_1.xpm", &a, &a);
	player->left_1 = mlx_xpm_file_to_image(data->mlx,
			"./srcs/cat_left_1.xpm", &a, &a);
	player->right_1 = mlx_xpm_file_to_image(data->mlx,
			"./srcs/cat_right_1.xpm", &a, &a);
	player->stand = mlx_xpm_file_to_image(data->mlx,
			"./srcs/cat_stand_1.xpm", &a, &a);
	ft_put_player(data, player);
}
