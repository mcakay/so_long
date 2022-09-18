/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:36:02 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/16 18:46:13 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_get_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map_width*64, data->map_heigth*64, "so_long");
	data->x = 0;
	data->y = 0;
}