/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 07:14:44 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:22:08 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_data *data, t_player *player)
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
			}
			j++;
		}
		i++;
	}
}

void	ft_find_x(t_data *data, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_heigth)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (strs[i][j] == 'x')
				ft_x(strs, i, j);
			j++;
		}
		i++;
	}
}

void	ft_find_e(t_data *data, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_heigth)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (strs[i][j] == 'E')
			{
				if (strs[i][j + 1] != 'x' && strs[i][j - 1] != 'x'
					&& strs[i + 1][j] != 'x' && strs[i - 1][j] != 'x')
				{
					ft_free(data, strs);
					ft_error();
				}
			}
			j++;
		}
		i++;
	}
	ft_free(data, strs);
}
