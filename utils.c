/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:05 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/18 03:23:58 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->x = 0;
	data->y = 0;
	ft_put_map(data);
	ft_put_collect(data, &(data->collect));
}

void	ft_check_collects(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->collect.total)
	{
		if (data->collect.collects[i][0] == x
			&& data->collect.collects[i][1] == y
			&& data->collect.collects[i][2] != 0)
		{
			data->collect.collected++;
			data->collect.collects[i][2] = 0;
		}
		i++;
	}
}

void	ft_sleep(long long time)
{
	int	i;

	i = 0;
	while (i < time)
		i++;
}