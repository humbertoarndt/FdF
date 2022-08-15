/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reproject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:51:47 by harndt            #+#    #+#             */
/*   Updated: 2022/08/12 22:14:56 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Create a img object
 * 
 * @param data To create and image.
 */
static void	create_img(t_win *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
										&data->img.line_len, &data->img.endian);
	render_background(&data->img, C_NIER_BG);
}

void	reproject(t_win *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->legend.mlx_img);
	create_img(data);
	draw_legend(data);
	rotate(data->fdf);
	projection(data->fdf);
	plot_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
							L_WIDTH, 0);
}
