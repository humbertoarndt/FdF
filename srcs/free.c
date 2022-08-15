/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 03:23:24 by harndt            #+#    #+#             */
/*   Updated: 2022/08/11 01:24:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief This function frees ervery data allocated in a t_fdf struct.
 * 
 * @param fdf The t_fdf to be freed.
 */

static void	free_fdf(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (fdf->points[y])
	{
		x = 0;
		while (fdf->points[y][x])
		{
			free(fdf->points[y][x]);
			x++;
		}
		free(fdf->points[y]);
		y++;
	}
	free(fdf->points);
}

void	free_all(t_win *data)
{
	free(data->fdf->controls);
	free_fdf(data->fdf);
}

void	print_error(char *error_msg)
{
	ft_printf(error_msg);
	exit(1);
}

int	end_program(t_win *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->legend.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->fdf->controls);
	free_fdf(data->fdf);
	free(data->fdf);
	free(data);
	exit(0);
}
