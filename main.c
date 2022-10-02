/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcakay <mcakay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:46:23 by mcakay            #+#    #+#             */
/*   Updated: 2022/09/19 03:34:38 by mcakay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx = mlx_init();
	if (argc != 2)
		return (1);
	ft_init_data(&data, argv[1]);
	mlx_loop(data.mlx);
	return (0);
}
