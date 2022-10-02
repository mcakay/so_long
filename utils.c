/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:57:05 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:19:01 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_count(t_data *data)
{
	data->player.count++;
	ft_printf("%d\n", data->player.count);
}

void	ft_display_move(t_data *data)
{
	char	*str;

	str = ft_itoa(data->player.count);
	mlx_string_put(data->mlx, data->win, 32, 32, 0, str);
	free(str);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_data *data, char **strs)
{
	int	i;

	i = 0;
	while (i < data->map_heigth)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_display_and_put(t_data *data, void *img)
{
	ft_display_move(data);
	mlx_put_image_to_window(data->mlx, data->win,
		img, data->player.x * 64, data->player.y * 64);
}
