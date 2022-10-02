/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:36:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:01:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx,
			data->map_width * 64, data->map_heigth * 64, "so_long");
	data->x = 0;
	data->y = 0;
}

void	ft_clear_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->x = 0;
	data->y = 0;
	ft_put_map(data);
	ft_put_collect(data, &(data->collect));
}
