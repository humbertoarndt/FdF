/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:25:57 by harndt            #+#    #+#             */
/*   Updated: 2022/08/09 23:02:55 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pix_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

/**
 * @brief This function finish drawing the menu.
 * 
 * @param data The data struct.
 * @param y The line heigth.
 */
static void	draw_legend_2(t_win *data, int y)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 35, C_WHT, \
					"PROJECTIONS:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_TXT, \
					"ISOMETRIC: '1'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_TXT, \
					"DIMETRIC: '2'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_NIER_TXT, \
					"CONIC: '3'");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (L_WIDTH - 70), \
					(W_HEIGHT - 20), C_NIER_TXT, "by: harndt");
}

void	draw_legend(t_win *data)
{
	int	y;

	y = 0;
	data->legend.mlx_img = mlx_new_image(data->mlx_ptr, L_WIDTH, W_HEIGHT);
	data->legend.addr = mlx_get_data_addr(data->legend.mlx_img, \
			&data->legend.bpp, &data->legend.line_len, &data->legend.endian);
	render_background(&data->legend, C_NIER_BG_L);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->legend.mlx_img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 20, C_WHT, \
					"HOW TO USE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"COLOR: 'C' Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"ZOOM: Scroll Mouse");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"MOVE: Right Click");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"ALTITUDE: 'A' and 'S' Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"ROTATE: Arrow Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 25, C_NIER_TXT, \
					"RESET: 'D' Key");
	draw_legend_2(data, y);
}
