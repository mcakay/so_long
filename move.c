/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:15:56 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/18 03:24:47 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "key.h"

static void	ft_moveup(t_data *data)
{
	ft_clear_window(data);
	if (data->map[data->player.y - 1][data->player.x] == 'C')
	{
		ft_check_collects(data, data->player.y - 1, data->player.x);
		ft_clear_window(data);
	}
	if (data->map[data->player.y - 1][data->player.x] != '1')
	{
		if (data->map[data->player.y - 1][data->player.x] == 'E')
		{
			if (data->collect.collected == data->collect.total)
			{
				data->player.y--;
				mlx_destroy_window(data->mlx, data->win);
				exit(0);
			}
		}
		else
			data->player.y--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.back_1, data->player.x*64, data->player.y*64);
}

static void	ft_movedown(t_data *data)
{
	ft_clear_window(data);
	if (data->map[data->player.y + 1][data->player.x] == 'C')
	{
		ft_check_collects(data, data->player.y + 1, data->player.x);
		ft_clear_window(data);
	}
	if (data->map[data->player.y + 1][data->player.x] != '1')
	{
		if (data->map[data->player.y + 1][data->player.x] == 'E')
		{
			if (data->collect.collected == data->collect.total)
			{
				mlx_destroy_window(data->mlx, data->win);
				exit(0);
			}
		}
		else
			data->player.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.front_1, data->player.x*64, data->player.y*64);
}

static void	ft_moveleft(t_data *data)
{
	ft_clear_window(data);
	if (data->map[data->player.y][data->player.x - 1] == 'C')
	{
		ft_check_collects(data, data->player.y, data->player.x - 1);
		ft_clear_window(data);
	}
	if (data->map[data->player.y][data->player.x - 1] != '1')
	{
		if (data->map[data->player.y][data->player.x - 1] == 'E')
		{
			if (data->collect.collected == data->collect.total)
			{
				data->player.x--;
				mlx_destroy_window(data->mlx, data->win);
				exit(0);
			}
		}
		else
			data->player.x--;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.left_1, data->player.x*64, data->player.y*64);
}

static void	ft_moveright(t_data *data)
{
	ft_clear_window(data);
	if (data->map[data->player.y][data->player.x + 1] == 'C')
	{
		ft_check_collects(data, data->player.y, data->player.x + 1);
		ft_clear_window(data);
	}
	if (data->map[data->player.y][data->player.x + 1] != '1')
	{
		if (data->map[data->player.y][data->player.x + 1] == 'E')
		{
			if (data->collect.collected == data->collect.total)
			{
				data->player.x++;
				mlx_destroy_window(data->mlx, data->win);
				exit(0);
			}
		}
		else
			data->player.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->player.right_1, data->player.x*64, data->player.y*64);
}

int	ft_move(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		ft_moveup(data);
	if (keycode == KEY_A)
		ft_moveleft(data);
	if (keycode == KEY_S)
		ft_movedown(data);
	if (keycode == KEY_D)
		ft_moveright(data);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}