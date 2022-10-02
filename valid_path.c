/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 01:19:26 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:21:32 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_copy(t_data *data)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * data->map_heigth);
	while (i < data->map_heigth)
	{
			strs[i] = ft_strdup(data->map[i]);
			i++;
	}
	return (strs);
}

void	ft_x(char **strs, int y, int x)
{
	int	start_x;

	start_x = x;
	while (strs[y][x + 1] != '1' && strs[y][x + 1] != 'E')
	{
		strs[y][x + 1] = 'x';
		x++;
	}
	while (strs[y][x - 1] != '1' && strs[y][x - 1] != 'E')
	{
		strs[y][x - 1] = 'x';
		x--;
	}
	x = start_x;
	while (strs[y + 1][x] != '1' && strs[y + 1][x] != 'E')
	{
		strs[y + 1][x] = 'x';
		y++;
	}
	while (strs[y - 1][x] != '1' && strs[y - 1][x] != 'E')
	{
		strs[y - 1][x] = 'x';
		y--;
	}
}

static void	ft_is_valid(t_data *data, char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_heigth)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (strs[i][j] == 'C')
			{
				ft_free(data, strs);
				ft_error();
			}
			j++;
		}
		i++;
	}
	ft_find_e(data, strs);
}

void	ft_valid_path(t_data *data, t_player *player)
{
	char	**strs;
	int		a;

	strs = ft_copy(data);
	a = 0;
	ft_find_player(data, player);
	strs[player->y][player->x] = 'x';
	if (strs[player->y][player->x + 1] != '1'
		&& strs[player->y][player->x + 1] != 'E')
		strs[player->y][player->x + 1] = 'x';
	if (strs[player->y][player->x - 1] != '1'
		&& strs[player->y][player->x - 1] != 'E')
		strs[player->y][player->x - 1] = 'x';
	if (strs[player->y + 1][player->x] != '1'
		&& strs[player->y + 1][player->x] != 'E')
		strs[player->y + 1][player->x] = 'x';
	if (strs[player->y - 1][player->x] != '1'
		&& strs[player->y - 1][player->x] != 'E')
		strs[player->y - 1][player->x] = 'x';
	while (a < data->map_heigth * data->map_width)
	{
		ft_find_x(data, strs);
		a++;
	}
	ft_is_valid(data, strs);
}
