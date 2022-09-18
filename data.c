/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:50:37 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/18 03:28:24 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data *data, char *path)
{
	t_player	player;
	t_collect	collect;

	ft_calculate_map_size(data, path);
	ft_get_map(data, path);
	ft_get_window(data);
	ft_put_map(data);
	ft_init_player(data, &player);
	ft_init_collect(data, &collect);
	data->player = player;
	data->collect = collect;
	mlx_hook(data->win, 2, 0, &ft_move, data);
}