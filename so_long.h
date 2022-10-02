/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:46:38 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 08:19:09 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/srcb/ft_printf_bonus.h"
# include "./gnl/get_next_line.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_player
{
	void	*stand;
	void	*front_1;
	void	*left_1;
	void	*right_1;
	void	*back_1;
	int		x;
	int		y;
	int		count;
}				t_player;

typedef struct s_collect
{
	void	*img;
	int		total;
	int		**collects;
	int		collected;
}				t_collect;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*path;
	int			map_width;
	int			map_heigth;
	int			x;
	int			y;
	t_player	player;
	t_collect	collect;
}				t_data;

typedef struct s_map
{
	void	*floor;
	void	*wall;
	void	*exit;
}				t_map;

typedef struct s_check
{
	int	c_len;
	int	p_len;
	int	e_len;
	int	i;
	int	j;
	int	temp;
}				t_check;

void	ft_init_data(t_data *data, char *path);
void	ft_calculate_map_size(t_data *data, char *path);
void	ft_get_map(t_data *data, char *path);
void	ft_put_map(t_data *data);
void	ft_check_map(t_data *data);
void	ft_get_window(t_data *data);
void	ft_clear_window(t_data *data);
void	ft_init_player(t_data *data, t_player *player);
void	ft_put_player(t_data *data, t_player *player);
int		ft_move(int keycode, t_data *data);
void	ft_move_count(t_data *data);
void	ft_error(void);
void	ft_display_move(t_data *data);
void	ft_free(t_data *data, char **strs);
void	ft_display_and_put(t_data *data, void *img);
void	ft_init_collect(t_data *data, t_collect *collect);
void	ft_put_collect(t_data *data, t_collect *collect);
void	ft_check_collects(t_data *data, int x, int y);
void	ft_valid_path(t_data *data, t_player *player);
void	ft_x(char **strs, int y, int x);
void	ft_find_player(t_data *data, t_player *player);
void	ft_find_x(t_data *data, char **strs);
void	ft_find_e(t_data *data, char **strs);

#endif