/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:03:53 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/16 16:12:37 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_init_player_front(t_data *data, t_player *player, int *a)
{
	player->front_1 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_front_1", a, a);
	player->front_2 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_front_2", a, a);
	player->front_3 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_front_3", a, a);
	player->front_4 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_front_4", a, a);
	player->back_1 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_back_1", a, a);
	player->back_2 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_back_2", a, a);
	player->back_3 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_back_3", a, a);
	player->back_4 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_back_4", a, a);
}

static void ft_init_player_left_right(t_data *data, t_player *player, int *a)
{
	player->left_1 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_left_1", a, a);
	player->left_2 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_left_2", a, a);
	player->left_3 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_left_3", a, a);
	player->left_4 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_left_4", a, a);
	player->right_1 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_right_1", a, a);
	player->right_2 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_right_2", a, a);
	player->right_3 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_right_3", a, a);
	player->right_4 = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_right_4", a, a);
}

static void ft_init_player_stand_sleep(t_data *data, t_player *player, int *a)
{
	player->stand = mlx_xpm_file_to_image(data->mlx, "./srcs/cat_stand", a, a);
}

void	ft_init_player(t_data *data, t_player *player)
{
	int	a;

	a = 64;
	ft_init_player_front_back(data, player, &a);
	ft_init_player_left_right(data, player, &a);
	ft_init_player_stand_sleep(data, player, &a);
}