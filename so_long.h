/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:46:38 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/16 16:03:50 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/srcb/ft_printf_bonus.h"
# include "./gnl/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_heigth;
	int		x;
	int		y;
}				t_data;

typedef struct s_map
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
}				t_map;

typedef struct s_player
{
	void	*stand;
	void	*front_1;
	void	*front_2;
	void	*front_3;
	void	*front_4;
	void	*left_1;
	void	*left_2;
	void	*left_3;
	void	*left_4;
	void	*right_1;
	void	*right_2;
	void	*right_3;
	void	*right_4;
	void	*back_1;
	void	*back_2;
	void	*back_3;
	void	*back_4;
}				t_player;

//data
void	ft_init_data(t_data *data, char *path);

//map
void	ft_calculate_map_size(t_data *data, char *path);
void	ft_get_map(t_data *data, char *path);
void	ft_put_map(t_data *data);

//window
void ft_get_window(t_data *data);

#endif