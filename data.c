/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:50:37 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 07:22:44 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_xbutton(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	ft_init_data(t_data *data, char *path)
{
	t_player	player;
	t_collect	collect;

	ft_calculate_map_size(data, path);
	ft_get_map(data, path);
	ft_check_map(data);
	ft_valid_path(data, &player);
	ft_get_window(data);
	ft_put_map(data);
	ft_init_collect(data, &collect);
	ft_init_player(data, &player);
	data->player = player;
	data->collect = collect;
	mlx_string_put(data->mlx, data->win, 32, 32, 0, "0");
	mlx_hook(data->win, 17, 0, &ft_xbutton, data);
	mlx_hook(data->win, 2, 0, &ft_move, data);
}
