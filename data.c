/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:50:37 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/16 16:13:07 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data *data, char *path)
{
	ft_calculate_map_size(data, path);
	ft_get_map(data, path);
	ft_get_window(data);
	ft_put_map(data);
}